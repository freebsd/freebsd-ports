# Created by: Hugo Leisink
# $FreeBSD$

PORTNAME=	hiawatha
PORTVERSION=	10.3
PORTREVISION=	1
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

CMAKE_ARGS=	-DCMAKE_INSTALL_LOCALSTATEDIR=/var \
		-DCMAKE_INSTALL_MANDIR=${PREFIX}/man \
		-DWEBROOT_DIR=${WWWDIR}

OPTIONS_DEFINE=	CACHE DOCS IPV6 MONITOR RPROXY SSL TOMAHAWK TOOLKIT XSLT

OPTIONS_DEFAULT=	CACHE RPROXY SSL TOOLKIT XSLT

CACHE_DESC=	Enable cache support
MONITOR_DESC=	Enable Hiawatha Monitor
RPROXY_DESC=	Enable reverse proxy
TOMAHAWK_DESC=	Enable Tomahawk command channel
TOOLKIT_DESC=	Enable URL toolkit
XSLT_DESC=	Enable XSLT support

CACHE_CMAKE_ON=		-DENABLE_CACHE=on
CACHE_CMAKE_OFF=	-DENABLE_CACHE=off

TOMAHAWK_CMAKE_ON=	-DENABLE_TOMAHAWK=on
TOMAHAWK_CMAKE_OFF=	-DENABLE_TOMAHAWK=off

IPV6_CMAKE_ON=		-DENABLE_IPV6=on
IPV6_CMAKE_OFF=		-DENABLE_IPV6=off

MONITOR_CMAKE_ON=	-DENABLE_MONITOR=on
MONITOR_CMAKE_OFF=	-DENABLE_MONITOR=off

RPROXY_CMAKE_ON=	-DENABLE_RPROXY=on
RPROXY_CMAKE_OFF=	-DENABLE_RPROXY=off

SSL_CMAKE_ON=		-DENABLE_SSL=on
SSL_CMAKE_OFF=		-DENABLE_SSL=off

TOOLKIT_CMAKE_ON=	-DENABLE_TOOLKIT=on
TOOLKIT_CMAKE_OFF=	-DENABLE_TOOLKIT=off

XSLT_USE=		GNOME=libxslt
XSLT_CMAKE_ON=		-DENABLE_XSLT=on
XSLT_CMAKE_OFF=		-DENABLE_XSLT=off

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
