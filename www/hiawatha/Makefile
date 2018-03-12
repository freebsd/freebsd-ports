# Created by: Hugo Leisink
# $FreeBSD$

PORTNAME=	hiawatha
PORTVERSION=	10.7
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	https://www.hiawatha-webserver.org/files/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Advanced and secure webserver for Unix

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

PORTDOCS=	ChangeLog README.md
CONFIG_FILES=	hiawatha.conf mimetype.conf cgi-wrapper.conf toolkit.conf \
		error.xslt index.xslt

SUB_FILES=	pkg-message
USES=		cmake compiler:c11
USE_LDCONFIG=	yes
USE_RC_SUBR=	hiawatha

LDFLAGS+=	-L${LOCALBASE}/lib
CMAKE_ARGS+=	-DCMAKE_INSTALL_LOCALSTATEDIR=/var \
		-DCMAKE_INSTALL_MANDIR=${PREFIX}/man \
		-DWEBROOT_DIR=${WWWDIR} \
		-DWORK_DIR=/var/db/${PORTNAME}

OPTIONS_DEFINE=	CACHE DOCS IPV6 MONITOR RPROXY MBEDTLS TOMAHAWK TOOLKIT XSLT

OPTIONS_DEFAULT=	CACHE RPROXY MBEDTLS TOOLKIT XSLT

CACHE_DESC=	Enable cache support
MONITOR_DESC=	Enable Hiawatha Monitor
RPROXY_DESC=	Enable reverse proxy
TOMAHAWK_DESC=	Enable Tomahawk command channel
TOOLKIT_DESC=	Enable URL toolkit
XSLT_DESC=	Enable XSLT support

CACHE_CMAKE_BOOL=	ENABLE_CACHE
TOMAHAWK_CMAKE_BOOL=	ENABLE_TOMAHAWK
IPV6_CMAKE_BOOL=	ENABLE_IPV6
MONITOR_CMAKE_BOOL=	ENABLE_MONITOR
RPROXY_CMAKE_BOOL=	ENABLE_RPROXY
MBEDTLS_CMAKE_BOOL=	ENABLE_TLS USE_SYSTEM_MBEDTLS
TOOLKIT_CMAKE_BOOL=	ENABLE_TOOLKIT
XSLT_USE=		GNOME=libxslt
XSLT_CMAKE_BOOL=	ENABLE_XSLT

MBEDTLS_LIB_DEPENDS=	libmbedtls.so:security/mbedtls

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g' \
	${WRKSRC}/man/hiawatha.1.in ${WRKSRC}/man/cgi-wrapper.1.in \
	${WRKSRC}/config/cgi-wrapper.conf ${WRKSRC}/config/hiawatha.conf.in

	@${REINPLACE_CMD} -e 's|/etc/hiawatha|${ETCDIR}|g' \
	${WRKSRC}/man/hiawatha.1.in ${WRKSRC}/man/cgi-wrapper.1.in

post-install:
.for FILE in ${CONFIG_FILES}
	${INSTALL_DATA} ${WRKSRC}/config/${FILE} ${STAGEDIR}${PREFIX}/etc/hiawatha/${FILE}.sample
.endfor

	@${MKDIR} ${STAGEDIR}${WWWDIR} ; \
	${INSTALL_DATA} ${WRKSRC}/extra/index.html ${STAGEDIR}${WWWDIR}/index.html.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
