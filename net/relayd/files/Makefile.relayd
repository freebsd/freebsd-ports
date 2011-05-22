# $FreeBSD$

PROG=	relayd

MAN=	relayd.8 \
	relayd.conf.5

.PATH:	${.CURDIR}/../../lib/libutil
SRCS=	imsg-buffer.c \
	imsg.c

.PATH:	${.CURDIR}
SRCS+=	parse.y \
	log.c \
	control.c \
	ssl.c \
	ssl_privsep.c \
	relayd.c \
	pfe.c \
	pfe_filter.c \
	hce.c \
	relay.c \
	relay_udp.c \
	check_icmp.c \
	check_tcp.c \
	check_script.c \
	name2id.c \
	arc4random.c \
	shuffle.c \
	proc.c \
	config.c

CFLAGS+=	-DSHA1_DIGEST_LENGTH=SHA_DIGEST_LENGTH \
		-DSHA1_DIGEST_STRING_LENGTH=SHA_DIGEST_LENGTH \
		-DOPENSSL_NO_SHA -DOPENSSL_NO_MD5 \
		-D__dead=''
CFLAGS+=	-I${.CURDIR} -I${.CURDIR}/../../lib/libutil \
		-I${PREFIX}/include
CLEANFILES+=	y.tab.h

LDADD=		-lmd -L${PREFIX}/lib ${LIBEVENT} -lssl -lcrypto
DPADD=		${LIBEVENT} ${LIBSSL} ${LIBCRYPTO}

.include <bsd.prog.mk>
