# $FreeBSD$

PORTNAME=	obhttpd
PORTVERSION=	6.3.20180803
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	koue@chaosophia.net
COMMENT=	OpenBSD http server

LICENSE=	BSD3CLAUSE

WRKSRC_SUBDIR=	src

USES=		ssl uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	koue
GH_PROJECT=	httpd

USE_RC_SUBR=	obhttpd

CFLAGS+=	-Wall

MAKE_ARGS+=	MANDIR=${PREFIX}/man/man

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

.if ! ${SSL_DEFAULT:Mlibressl*}
. ifnmake describe
STAGEDIR_libressl!=	${MAKE} -V STAGEDIR -C ${PORTSDIR}/security/libressl
. endif
BUILD_DEPENDS+= 	${NONEXISTENT}:security/libressl:stage
CFLAGS+=		-I${STAGEDIR_libressl}${LOCALBASE}/include

post-configure:
	${REINPLACE_CMD} 's|-ltls|${STAGEDIR_libressl}${LOCALBASE}/lib/libtls.a|g' \
		${WRKSRC}/usr.sbin/httpd/Makefile
	${REINPLACE_CMD} 's|-lssl|${STAGEDIR_libressl}${LOCALBASE}/lib/libssl.a|g' \
		 ${WRKSRC}/usr.sbin/httpd/Makefile
	${REINPLACE_CMD} 's|-lcrypto|${STAGEDIR_libressl}${LOCALBASE}/lib/libcrypto.a|g' \
		${WRKSRC}/usr.sbin/httpd/Makefile
	${REINPLACE_CMD} 's|-lcrypto|${STAGEDIR_libressl}${LOCALBASE}/lib/libcrypto.a|g' \
		${WRKSRC}/usr.bin/htpasswd/Makefile
.endif # SSL_DEFAULT

.include <bsd.port.post.mk>
