--- libfreerdp/core/tcp.c.orig	2014-09-11 22:46:32 UTC
+++ libfreerdp/core/tcp.c
@@ -71,6 +71,7 @@
 #include <winpr/stream.h>
 
 #include "tcp.h"
+#include "../crypto/opensslcompat.h"
 
 /* Simple Socket BIO */
 
@@ -86,13 +87,14 @@ static int transport_bio_simple_write(BIO* bio, const 
 {
 	int error;
 	int status = 0;
+	int socket = (int)BIO_get_data(bio);
 
 	if (!buf)
 		return 0;
 
 	BIO_clear_flags(bio, BIO_FLAGS_WRITE);
 
-	status = _send((SOCKET) bio->num, buf, size, 0);
+	status = _send(socket, buf, size, 0);
 
 	if (status <= 0)
 	{
@@ -116,13 +118,14 @@ static int transport_bio_simple_read(BIO* bio, char* b
 {
 	int error;
 	int status = 0;
+	int socket = (int)BIO_get_data(bio);
 
 	if (!buf)
 		return 0;
 
 	BIO_clear_flags(bio, BIO_FLAGS_READ);
 
-	status = _recv((SOCKET) bio->num, buf, size, 0);
+	status = _recv(socket, buf, size, 0);
 	if (status > 0)
 		return status;
 
@@ -160,6 +163,7 @@ static int transport_bio_simple_gets(BIO* bio, char* s
 static long transport_bio_simple_ctrl(BIO* bio, int cmd, long arg1, void* arg2)
 {
 	int status = -1;
+	int socket = (int)BIO_get_data(bio);
 
 	switch (cmd)
 	{
@@ -167,29 +171,29 @@ static long transport_bio_simple_ctrl(BIO* bio, int cm
 			if (arg2)
 			{
 				transport_bio_simple_free(bio);
-				bio->flags = BIO_FLAGS_SHOULD_RETRY;
-				bio->num = *((int*) arg2);
-				bio->shutdown = (int) arg1;
-				bio->init = 1;
+				BIO_set_flags(bio, BIO_FLAGS_SHOULD_RETRY);
+				BIO_set_data(bio, *((int *) arg2));
+				BIO_set_shutdown(bio, (int) arg1);
+				BIO_set_init(bio, 1);
 				status = 1;
 			}
 			break;
 
 		case BIO_C_GET_FD:
-			if (bio->init)
+			if (BIO_get_init(bio))
 			{
 				if (arg2)
-					*((int*) arg2) = bio->num;
-				status = bio->num;
+					*((int*) arg2) = socket;
+				status = socket;
 			}
 			break;
 
 		case BIO_CTRL_GET_CLOSE:
-			status = bio->shutdown;
+			status = BIO_get_shutdown(bio);
 			break;
 
 		case BIO_CTRL_SET_CLOSE:
-			bio->shutdown = (int) arg1;
+			BIO_set_shutdown(bio, (int) arg1);
 			status = 1;
 			break;
 
@@ -211,47 +215,49 @@ static long transport_bio_simple_ctrl(BIO* bio, int cm
 
 static int transport_bio_simple_new(BIO* bio)
 {
-	bio->init = 0;
-	bio->num = 0;
-	bio->ptr = NULL;
-	bio->flags = BIO_FLAGS_SHOULD_RETRY;
+
+	BIO_set_init(bio, 0);
+	BIO_set_data(bio, 0);
+	BIO_set_flags(bio, BIO_FLAGS_SHOULD_RETRY);
 	return 1;
 }
 
 static int transport_bio_simple_free(BIO* bio)
 {
+	int socket = (int)BIO_get_data(bio);
 	if (!bio)
 		return 0;
 
-	if (bio->shutdown)
+	if (BIO_get_shutdown(bio))
 	{
-		if (bio->init)
-			closesocket((SOCKET) bio->num);
+		if (BIO_get_init(bio))
+			closesocket(socket);
 
-		bio->init = 0;
-		bio->flags = 0;
+		BIO_set_init(bio, 0);
+		BIO_set_flags(bio, 0);
+		BIO_set_data(bio, 0);
 	}
 
 	return 1;
 }
 
-static BIO_METHOD transport_bio_simple_socket_methods =
-{
-	BIO_TYPE_SIMPLE,
-	"SimpleSocket",
-	transport_bio_simple_write,
-	transport_bio_simple_read,
-	transport_bio_simple_puts,
-	transport_bio_simple_gets,
-	transport_bio_simple_ctrl,
-	transport_bio_simple_new,
-	transport_bio_simple_free,
-	NULL,
-};
-
 BIO_METHOD* BIO_s_simple_socket(void)
 {
-	return &transport_bio_simple_socket_methods;
+	static BIO_METHOD* bio_methods = NULL;
+
+	if (bio_methods == NULL)
+	{
+		if (!(bio_methods = BIO_meth_new(BIO_TYPE_SIMPLE, "SimpleSocket")))
+			return NULL;
+		BIO_meth_set_write(bio_methods, transport_bio_simple_write);
+		BIO_meth_set_read(bio_methods, transport_bio_simple_read);
+		BIO_meth_set_puts(bio_methods, transport_bio_simple_puts);
+		BIO_meth_set_gets(bio_methods, transport_bio_simple_gets);
+		BIO_meth_set_ctrl(bio_methods, transport_bio_simple_ctrl);
+		BIO_meth_set_create(bio_methods, transport_bio_simple_new);
+		BIO_meth_set_destroy(bio_methods, transport_bio_simple_free);
+	}
+	return bio_methods;
 }
 
 /* Buffered Socket BIO */
@@ -264,7 +270,8 @@ long transport_bio_buffered_callback(BIO* bio, int mod
 static int transport_bio_buffered_write(BIO* bio, const char* buf, int num)
 {
 	int status, ret;
-	rdpTcp* tcp = (rdpTcp*) bio->ptr;
+	rdpTcp* tcp = (rdpTcp*) BIO_get_data(bio);
+	BIO *next_bio = NULL;
 	int nchunks, committedBytes, i;
 	DataChunk chunks[2];
 
@@ -283,23 +290,24 @@ static int transport_bio_buffered_write(BIO* bio, cons
 
 	committedBytes = 0;
 	nchunks = ringbuffer_peek(&tcp->xmitBuffer, chunks, ringbuffer_used(&tcp->xmitBuffer));
+	next_bio = BIO_next(bio);
 
 	for (i = 0; i < nchunks; i++)
 	{
 		while (chunks[i].size)
 		{
-			status = BIO_write(bio->next_bio, chunks[i].data, chunks[i].size);
+			status = BIO_write(next_bio, chunks[i].data, chunks[i].size);
 
 			if (status <= 0)
 			{
-				if (!BIO_should_retry(bio->next_bio))
+				if (!BIO_should_retry(next_bio))
 				{
 					BIO_clear_flags(bio, BIO_FLAGS_SHOULD_RETRY);
 					ret = -1; /* fatal error */
 					goto out;
 				}
 
-				if (BIO_should_write(bio->next_bio))
+				if (BIO_should_write(next_bio))
 				{
 					BIO_set_flags(bio, BIO_FLAGS_WRITE);
 					tcp->writeBlocked = TRUE;
@@ -321,16 +329,17 @@ out:
 static int transport_bio_buffered_read(BIO* bio, char* buf, int size)
 {
 	int status;
-	rdpTcp* tcp = (rdpTcp*) bio->ptr;
+	rdpTcp* tcp = (rdpTcp*) BIO_get_data(bio);
+	BIO* next_bio = BIO_next(bio);
 
 	tcp->readBlocked = FALSE;
 	BIO_clear_flags(bio, BIO_FLAGS_READ);
 
-	status = BIO_read(bio->next_bio, buf, size);
+	status = BIO_read(next_bio, buf, size);
 
 	if (status <= 0)
 	{
-		if (!BIO_should_retry(bio->next_bio))
+		if (!BIO_should_retry(next_bio))
 		{
 			BIO_clear_flags(bio, BIO_FLAGS_SHOULD_RETRY);
 			goto out;
@@ -338,7 +347,7 @@ static int transport_bio_buffered_read(BIO* bio, char*
 
 		BIO_set_flags(bio, BIO_FLAGS_SHOULD_RETRY);
 
-		if (BIO_should_read(bio->next_bio))
+		if (BIO_should_read(next_bio))
 		{
 			BIO_set_flags(bio, BIO_FLAGS_READ);
 			tcp->readBlocked = TRUE;
@@ -362,7 +371,7 @@ static int transport_bio_buffered_gets(BIO* bio, char*
 
 static long transport_bio_buffered_ctrl(BIO* bio, int cmd, long arg1, void* arg2)
 {
-	rdpTcp* tcp = (rdpTcp*) bio->ptr;
+	rdpTcp* tcp = (rdpTcp*) BIO_get_data(bio);
 
 	switch (cmd)
 	{
@@ -376,7 +385,7 @@ static long transport_bio_buffered_ctrl(BIO* bio, int 
 			return 0;
 
 		default:
-			return BIO_ctrl(bio->next_bio, cmd, arg1, arg2);
+			return BIO_ctrl(BIO_next(bio), cmd, arg1, arg2);
 	}
 
 	return 0;
@@ -384,10 +393,9 @@ static long transport_bio_buffered_ctrl(BIO* bio, int 
 
 static int transport_bio_buffered_new(BIO* bio)
 {
-	bio->init = 1;
-	bio->num = 0;
-	bio->ptr = NULL;
-	bio->flags = BIO_FLAGS_SHOULD_RETRY;
+	BIO_set_init(bio, 1);
+	BIO_set_data(bio, 0);
+	BIO_set_flags(bio, BIO_FLAGS_SHOULD_RETRY);
 	return 1;
 }
 
@@ -396,29 +404,28 @@ static int transport_bio_buffered_free(BIO* bio)
 	return 1;
 }
 
-static BIO_METHOD transport_bio_buffered_socket_methods =
-{
-	BIO_TYPE_BUFFERED,
-	"BufferedSocket",
-	transport_bio_buffered_write,
-	transport_bio_buffered_read,
-	transport_bio_buffered_puts,
-	transport_bio_buffered_gets,
-	transport_bio_buffered_ctrl,
-	transport_bio_buffered_new,
-	transport_bio_buffered_free,
-	NULL,
-};
-
 BIO_METHOD* BIO_s_buffered_socket(void)
 {
-	return &transport_bio_buffered_socket_methods;
+	static BIO_METHOD* bio_methods = NULL;
+	if (bio_methods == NULL)
+	{
+		if (!(bio_methods = BIO_meth_new(BIO_TYPE_BUFFERED, "BufferedSocket")))
+			return NULL;
+		BIO_meth_set_write(bio_methods, transport_bio_buffered_write);
+		BIO_meth_set_read(bio_methods, transport_bio_buffered_read);
+		BIO_meth_set_puts(bio_methods, transport_bio_buffered_puts);
+		BIO_meth_set_gets(bio_methods, transport_bio_buffered_gets);
+		BIO_meth_set_ctrl(bio_methods, transport_bio_buffered_ctrl);
+		BIO_meth_set_create(bio_methods, transport_bio_buffered_new);
+		BIO_meth_set_destroy(bio_methods, transport_bio_buffered_free);
+	}
+	return bio_methods;
 }
 
 BOOL transport_bio_buffered_drain(BIO *bio)
 {
 	int status;
-	rdpTcp* tcp = (rdpTcp*) bio->ptr;
+	rdpTcp* tcp = (rdpTcp*) BIO_get_data(bio);
 
 	if (!ringbuffer_used(&tcp->xmitBuffer))
 		return 1;
@@ -527,7 +534,10 @@ BOOL tcp_connect(rdpTcp* tcp, const char* hostname, in
 		if (!tcp->socketBio)
 			return FALSE;
 
-		if (BIO_set_conn_hostname(tcp->socketBio, hostname) < 0 || BIO_set_conn_int_port(tcp->socketBio, &port) < 0)
+		char strport[10];
+		/* XXX HACK */
+		snprintf(strport, 10, "%d", port);
+		if (BIO_set_conn_hostname(tcp->socketBio, hostname) < 0 || BIO_set_conn_port(tcp->socketBio, strport) < 0)
 			return FALSE;
 
 		BIO_set_nbio(tcp->socketBio, 1);
@@ -620,7 +630,7 @@ BOOL tcp_connect(rdpTcp* tcp, const char* hostname, in
 	if (!tcp->bufferedBio)
 		return FALSE;
 
-	tcp->bufferedBio->ptr = tcp;
+	BIO_set_data(tcp->bufferedBio, tcp);
 
 	tcp->bufferedBio = BIO_push(tcp->bufferedBio, tcp->socketBio);
 
@@ -771,7 +781,7 @@ int tcp_attach(rdpTcp* tcp, int sockfd)
 		if (!tcp->bufferedBio)
 			return FALSE;
 
-		tcp->bufferedBio->ptr = tcp;
+		BIO_set_data(tcp->bufferedBio, tcp);
 
 		tcp->bufferedBio = BIO_push(tcp->bufferedBio, tcp->socketBio);
 	}
