# Created by: Hugo Leisink
# $FreeBSD$

PORTNAME=	hiawatha
PORTVERSION=	10.8.3
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	https://www.hiawatha-webserver.org/files/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Advanced and secure webserver for Unix

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c11
USE_RC_SUBR=	hiawatha

CMAKE_ARGS=	-DCMAKE_INSTALL_LOCALSTATEDIR=/var \
		-DWEBROOT_DIR=${WWWDIR} \
		-DWORK_DIR=/var/db/${PORTNAME}
SUB_FILES=	pkg-message

OPTIONS_DEFINE=		CACHE CGIWRAPPER IPV6 LOADCHECK MBEDTLS MONITOR \
			RPROXY TOMAHAWK TOOLKIT XSLT
OPTIONS_DEFAULT=	CACHE CGIWRAPPER MBEDTLS RPROXY TOOLKIT XSLT
OPTIONS_SUB=		yes

CACHE_DESC=		Caching support
CGIWRAPPER_DESC=	Install cgi-wrapper(1) (needs setuid bit)
LOADCHECK_DESC=		Load check support (experimental)
MONITOR_DESC=		Hiawatha Monitor support
RPROXY_DESC=		Reverse proxy support
TOMAHAWK_DESC=		Tomahawk command shell support
TOOLKIT_DESC=		URL toolkit support
XSLT_DESC=		XSLT support

CACHE_CMAKE_BOOL=	ENABLE_CACHE
IPV6_CMAKE_BOOL=	ENABLE_IPV6
LOADCHECK_CMAKE_BOOL=	ENABLE_LOADCHECK
MBEDTLS_CMAKE_BOOL=	ENABLE_TLS USE_SYSTEM_MBEDTLS
MBEDTLS_LIB_DEPENDS=	libmbedtls.so:security/mbedtls
MBEDTLS_USES=		localbase:ldflags
MONITOR_CMAKE_BOOL=	ENABLE_MONITOR
RPROXY_CMAKE_BOOL=	ENABLE_RPROXY
TOMAHAWK_CMAKE_BOOL=	ENABLE_TOMAHAWK
TOOLKIT_CMAKE_BOOL=	ENABLE_TOOLKIT
XSLT_CMAKE_BOOL=	ENABLE_XSLT
XSLT_USES=		gnome
XSLT_USE=		GNOME=libxslt

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/ssi-cgi|${PREFIX}/bin/ssi-cgi|g' \
		-e 's|/usr/bin|${LOCALBASE}/bin|g' \
		${WRKSRC}/config/cgi-wrapper.conf \
		${WRKSRC}/config/hiawatha.conf.in
	@${REINPLACE_CMD} -e 's|/usr/sbin|${PREFIX}/sbin|g' \
		-e 's|/etc/hiawatha|${ETCDIR}|g' \
		${WRKSRC}/man/hiawatha.1.in \
		${WRKSRC}/man/cgi-wrapper.1.in

post-install:
.for f in hiawatha.conf mimetype.conf cgi-wrapper.conf toolkit.conf \
	error.xslt index.xslt
	${INSTALL_DATA} ${WRKSRC}/config/${f} \
		${STAGEDIR}${PREFIX}/etc/hiawatha/${f}.sample
.endfor
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/extra/index.html \
		${STAGEDIR}${WWWDIR}/index.html.sample

.include <bsd.port.mk>
