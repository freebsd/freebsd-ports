# $FreeBSD$

PORTNAME=	obhttpd
PORTVERSION=	6.6.20191023
CATEGORIES=	www
MASTER_SITES=	OPENBSD/LibreSSL:libressl
DISTFILES=	libressl-${SSL_VERSION}.tar.gz:libressl

MAINTAINER=	koue@chaosophia.net
COMMENT=	OpenBSD http server

LICENSE=	BSD3CLAUSE

WRKSRC_SUBDIR=	src

USES=		uidfix

SSL_VERSION=	3.0.2
USE_GITHUB=	yes
GH_ACCOUNT=	koue
GH_PROJECT=	httpd

USE_RC_SUBR=	obhttpd

CFLAGS+=	-Wall
CFLAGS+=	-I${WRKDIR}/libressl-${SSL_VERSION}/include

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

pre-configure:
	@(cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/libressl-${SSL_VERSION}.tar.gz ${EXTRACT_AFTER_ARGS})
	@(cd ${WRKDIR}/libressl-${SSL_VERSION} && ${SETENV} ./configure && ${SETENV} ${MAKE_ENV} ${MAKE})

post-configure:
	${REINPLACE_CMD} 's|-ltls|${WRKDIR}/libressl-${SSL_VERSION}/tls/.libs/libtls.a|g' \
		${WRKSRC}/usr.sbin/httpd/Makefile
	${REINPLACE_CMD} 's|-lssl|${WRKDIR}/libressl-${SSL_VERSION}/ssl/.libs/libssl.a|g' \
		 ${WRKSRC}/usr.sbin/httpd/Makefile
	${REINPLACE_CMD} 's|-lcrypto|${WRKDIR}/libressl-${SSL_VERSION}/crypto/.libs/libcrypto.a|g' \
		${WRKSRC}/usr.sbin/httpd/Makefile
	${REINPLACE_CMD} 's|-lcrypto|${WRKDIR}/libressl-${SSL_VERSION}/crypto/.libs/libcrypto.a|g' \
		${WRKSRC}/usr.bin/htpasswd/Makefile

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/examples/httpd.conf \
		${STAGEDIR}${PREFIX}/etc/obhttpd.conf.sample

.include <bsd.port.mk>
