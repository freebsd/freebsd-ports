# New ports collection makefile for: neon
# Date created:		13 October 2000
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	neon
PORTVERSION=	0.24.7
CATEGORIES=	www
MASTER_SITES=	http://www.webdav.org/neon/ \
		http://keyserver.kjsl.com/~jharris/distfiles/

MAINTAINER=	lev@FreeBSD.org
COMMENT=	An HTTP and WebDAV client library for Unix systems

LIB_DEPENDS=	expat.5:${PORTSDIR}/textproc/expat2

INSTALLS_SHLIB=	yes

.ifndef WITHOUT_OPENSSL
USE_OPENSSL=	yes
.endif

USE_GNOME=	gnomehack gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ssl \
		--enable-xml \
		--enable-shared \
		--with-expat \
		--with-libs=${PREFIX}

MAN1=	neon-config.1
MAN3=	ne_add_request_header.3 ne_addr_destroy.3 ne_addr_error.3 \
	ne_addr_first.3 ne_addr_next.3 ne_addr_resolve.3 ne_addr_result.3 \
	ne_buffer.3 ne_buffer_altered.3 ne_buffer_append.3 ne_buffer_clear.3 \
	ne_buffer_concat.3 ne_buffer_create.3 ne_buffer_destroy.3 \
	ne_buffer_finish.3 ne_buffer_grow.3 ne_buffer_ncreate.3 \
	ne_buffer_zappend.3 ne_calloc.3 ne_close_connection.3 \
	ne_forget_auth.3 ne_get_error.3 ne_get_status.3 ne_iaddr_cmp.3 \
	ne_iaddr_free.3 ne_iaddr_make.3 ne_iaddr_print.3 ne_malloc.3 \
	ne_oom_callback.3 ne_print_request_header.3 ne_qtoken.3 ne_realloc.3 \
	ne_request_create.3 ne_request_destroy.3 ne_request_dispatch.3 \
	ne_session_create.3 ne_session_destroy.3 ne_session_proxy.3 \
	ne_set_error.3 ne_set_expect100.3 ne_set_persist.3 \
	ne_set_proxy_auth.3 ne_set_read_timeout.3 \
	ne_set_request_body_buffer.3 ne_set_request_body_fd.3 \
	ne_set_server_auth.3 ne_set_useragent.3 ne_shave.3 ne_sock_init.3 \
	ne_ssl_cert_cmp.3 ne_ssl_cert_export.3 ne_ssl_cert_free.3 \
	ne_ssl_cert_identity.3 ne_ssl_cert_import.3 ne_ssl_cert_issuer.3 \
	ne_ssl_cert_read.3 ne_ssl_cert_signedby.3 ne_ssl_cert_subject.3 \
	ne_ssl_cert_write.3 ne_ssl_clicert_decrypt.3 \
	ne_ssl_clicert_encrypted.3 ne_ssl_clicert_free.3 \
	ne_ssl_clicert_name.3 ne_ssl_clicert_owner.3 ne_ssl_clicert_read.3 \
	ne_ssl_dname_cmp.3 ne_ssl_readable_dname.3 ne_ssl_set_verify.3 \
	ne_ssl_trust_cert.3 ne_ssl_trust_default_ca.3 ne_status.3 ne_strdup.3 \
	ne_strndup.3 ne_token.3 ne_version_match.3 ne_version_string.3 neon.3

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/man/*.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/man/*.3 ${MANPREFIX}/man/man3
.ifndef NOPORTDOCS
	(cd ${WRKSRC} ; ${MAKE} install-html)
	${INSTALL_DATA} ${WRKSRC}/doc/using-neon.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
