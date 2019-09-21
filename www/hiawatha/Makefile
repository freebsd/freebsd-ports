# Created by: Hugo Leisink
# $FreeBSD$

PORTNAME=	hiawatha
PORTVERSION=	10.10
CATEGORIES=	www
MASTER_SITES=	https://www.hiawatha-webserver.org/files/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Advanced and secure webserver for Unix

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libmbedtls.so:security/mbedtls

USES=		cmake:insource compiler:c11 localbase:ldflags shebangfix
USE_RC_SUBR=	hiawatha
SHEBANG_FILES=	extra/letsencrypt/lefh.in

CMAKE_ARGS=	-DCMAKE_INSTALL_LOCALSTATEDIR=/var \
		-DWEBROOT_DIR=${WWWDIR} \
		-DWORK_DIR=/var/db/${PORTNAME}
CMAKE_ON=	USE_SYSTEM_MBEDTLS

OPTIONS_DEFINE=		CACHE CGIWRAPPER LEFH LOADCHECK MONITOR RPROXY TOMAHAWK \
			TOOLKIT XSLT
OPTIONS_DEFAULT=	CACHE CGIWRAPPER RPROXY TOOLKIT XSLT
OPTIONS_SUB=		yes

CACHE_DESC=		Caching support
CGIWRAPPER_DESC=	Install cgi-wrapper(1) (needs setuid bit)
LEFH_DESC=		Install Let's Encrypt For Hiawatha script
LOADCHECK_DESC=		Load check support (experimental)
MONITOR_DESC=		Hiawatha Monitor support
RPROXY_DESC=		Reverse proxy support
TOMAHAWK_DESC=		Tomahawk command shell support
TOOLKIT_DESC=		URL toolkit support
XSLT_DESC=		XSLT support

CACHE_CMAKE_BOOL=	ENABLE_CACHE
LEFH_USES=		php:cli
LOADCHECK_CMAKE_BOOL=	ENABLE_LOADCHECK
MONITOR_CMAKE_BOOL=	ENABLE_MONITOR
RPROXY_CMAKE_BOOL=	ENABLE_RPROXY
TOMAHAWK_CMAKE_BOOL=	ENABLE_TOMAHAWK
TOOLKIT_CMAKE_BOOL=	ENABLE_TOOLKIT
XSLT_USES=		gnome
XSLT_USE=		GNOME=libxslt
XSLT_CMAKE_BOOL=	ENABLE_XSLT

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
