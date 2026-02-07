PORTNAME=	obhttpd
DISTVERSION=	7.4.20231129
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	OPENBSD/LibreSSL:libressl
DISTFILES=	libressl-${SSL}.tar.gz:libressl

MAINTAINER=	koue@chaosophia.net
COMMENT=	OpenBSD http server
WWW=		https://github.com/koue/httpd

LICENSE=	BSD3CLAUSE

USES=		uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	koue
GH_PROJECT=	httpd \
		libevent:libevent \
		libimsg:libimsg
GH_TAGNAME=	${LIBIMSG}:libimsg \
		${LIBEVENT}:libevent

USE_RC_SUBR=	obhttpd

MAKE_ARGS+=	MANDIR=${PREFIX}/share/man/man

# XXX Static libraries with PIE are currently unsupported.
MAKE_ARGS+=	WITHOUT_PIE=true

CFLAGS+=	-Wall -fcommon \
		-I${WRKDIR}/libressl-${SSL}/include \
		-I${WRKSRC_libimsg}/src/lib/libutil \
		-I${WRKSRC_libevent}/src/lib/libevent

USERS=		www
GROUPS=		www

SSL=		3.8.2
LIBEVENT=	7.3.20230714
LIBIMSG=	7.3.20230714

post-patch:
	${REINPLACE_CMD} -e 's|libimsg/src||g' \
			 -e 's|libevent||g' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|httpd$$|obhttpd|g' \
			 -e 's|httpd.conf.5|obhttpd.conf.5|g' \
			 -e 's|httpd.8|obhttpd.8|g' ${WRKSRC}/src/usr.sbin/httpd/Makefile
	${REINPLACE_CMD} -e 's|htpasswd$$|obhtpasswd|g' \
			 -e 's|htpasswd.1|obhtpasswd.1|g' ${WRKSRC}/src/usr.bin/htpasswd/Makefile
	${MV} ${WRKSRC}/src/usr.bin/htpasswd/htpasswd.1 ${WRKSRC}/src/usr.bin/htpasswd/obhtpasswd.1
	${MV} ${WRKSRC}/src/usr.sbin/httpd/httpd.conf.5 ${WRKSRC}/src/usr.sbin/httpd/obhttpd.conf.5
	${MV} ${WRKSRC}/src/usr.sbin/httpd/httpd.8 ${WRKSRC}/src/usr.sbin/httpd/obhttpd.8
	${REINPLACE_CMD} -e 's|/etc/httpd.conf|${PREFIX}/etc/obhttpd.conf|g' \
		${WRKSRC}/src/usr.sbin/httpd/httpd.h

pre-configure:
	@(cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/libressl-${SSL}.tar.gz ${EXTRACT_AFTER_ARGS})
	@(cd ${WRKDIR}/libressl-${SSL} && ${SETENV} ac_cv_header_endian_h=no ./configure && ${SETENV} ${MAKE_ENV} ${MAKE})
	@(cd ${WRKSRC_libimsg} && ${SETENV} ${MAKE_ENV} ${MAKE})
	@(cd ${WRKSRC_libevent} && ${SETENV} ${MAKE_ENV} ${MAKE})

post-configure:
	${REINPLACE_CMD} 's|../../../libevent/src/lib/libevent/libevent.a|${WRKSRC_libevent}/src/lib/libevent/libevent.a|g' \
		${WRKSRC}/src/usr.sbin/httpd/Makefile
	${REINPLACE_CMD} 's|../../../libimsg/src/lib/libutil/libimsg.a|${WRKSRC_libimsg}/src/lib/libutil/libimsg.a|g' \
		${WRKSRC}/src/usr.sbin/httpd/Makefile
	${REINPLACE_CMD} 's|/usr/local/lib/libtls.a|${WRKDIR}/libressl-${SSL}/tls/.libs/libtls.a|g' \
		${WRKSRC}/src/usr.sbin/httpd/Makefile
	${REINPLACE_CMD} 's|/usr/local/lib/libssl.a|${WRKDIR}/libressl-${SSL}/ssl/.libs/libssl.a|g' \
		${WRKSRC}/src/usr.sbin/httpd/Makefile
	${REINPLACE_CMD} 's|/usr/local/lib/libcrypto.a|${WRKDIR}/libressl-${SSL}/crypto/.libs/libcrypto.a|g' \
		${WRKSRC}/src/usr.sbin/httpd/Makefile
	${REINPLACE_CMD} 's|/usr/local/lib/libcrypto.a|${WRKDIR}/libressl-${SSL}/crypto/.libs/libcrypto.a|g' \
		${WRKSRC}/src/usr.bin/htpasswd/Makefile

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/etc/examples/httpd.conf \
		${STAGEDIR}${PREFIX}/etc/obhttpd.conf.sample

.include <bsd.port.mk>
