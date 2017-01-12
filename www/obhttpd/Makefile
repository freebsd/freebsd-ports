# $FreeBSD$

PORTNAME=	obhttpd
PORTVERSION=	6.0.20161006
CATEGORIES=	www

MAINTAINER=	koue@chaosophia.net
COMMENT=	OpenBSD http server

LICENSE=	BSD3CLAUSE

WRKSRC_SUBDIR=	src

USE_GITHUB=	yes
GH_ACCOUNT=	koue
GH_PROJECT=	httpd

USE_RC_SUBR=	obhttpd
USES=		ssl uidfix

CFLAGS+=	-Wall

MAKE_ARGS+=	BINDIR=${PREFIX}/sbin MANDIR=${PREFIX}/man/man

USERS=		www
GROUPS=		www

post-patch:
	${REINPLACE_CMD} -e 's|httpd$$|obhttpd|g' \
			 -e 's|httpd.conf.5|obhttpd.conf.5|g' \
			 -e 's|httpd.8|obhttpd.8|g' ${WRKSRC}/usr.sbin/httpd/Makefile
	${REINPLACE_CMD} -e 's|htpasswd$$|obhtpasswd|g' \
			 -e 's|htpasswd.1|obhtpasswd.1|g' ${WRKSRC}/usr.bin/htpasswd/Makefile
	${MV} ${WRKSRC}/usr.bin/htpasswd/htpasswd.1 ${WRKSRC}/usr.bin/htpasswd/obhtpasswd.1
	${MV} ${WRKSRC}/usr.sbin/httpd/httpd.conf.5 ${WRKSRC}/usr.sbin/httpd/obhttpd.conf.5
	${MV} ${WRKSRC}/usr.sbin/httpd/httpd.8 ${WRKSRC}/usr.sbin/httpd/obhttpd.8
	${REINPLACE_CMD} -e 's|/etc/httpd.conf|${PREFIX}/etc/obhttpd.conf|g' \
		${WRKSRC}/usr.sbin/httpd/httpd.h

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/examples/httpd.conf \
		${STAGEDIR}${PREFIX}/etc/obhttpd.conf.sample

.include <bsd.port.pre.mk>

.if empty(SSL_DEFAULT:Mlibressl*)
IGNORE=		needs LibreSSL to build. Set DEFAULT_VERSIONS+=ssl=libressl and rebuild everything
.endif

.include <bsd.port.post.mk>
