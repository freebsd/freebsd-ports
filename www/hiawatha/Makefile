# Created by: Hugo Leisink
# $FreeBSD$

PORTNAME=	hiawatha
PORTVERSION=	9.3.1
CATEGORIES=	www
MASTER_SITES=	http://www.hiawatha-webserver.org/files/ \
		http://www.c-s.li/ports/

MAINTAINER=	c.petrik.sosa@gmail.com
COMMENT=	Advanced and secure webserver for Unix

LICENSE=	GPLv2

PORTDOCS=	ChangeLog README.md
CONFIG_FILES=	hiawatha.conf mimetype.conf cgi-wrapper.conf toolkit.conf \
		index.xslt

SUB_FILES=	pkg-message
USES=		cmake
USE_LDCONFIG=	yes
USE_RC_SUBR=	hiawatha
WANT_GNOME=	yes

CMAKE_ARGS+=	-DCMAKE_INSTALL_BINDIR=${PREFIX}/bin \
		-DCMAKE_INSTALL_SBINDIR=${PREFIX}/sbin \
		-DCMAKE_INSTALL_SYSCONFDIR=${ETCDIR} \
		-DCMAKE_INSTALL_LIBDIR=${PREFIX}/lib \
		-DCONFIG_DIR=${ETCDIR} \
		-DWEBROOT_DIR=${WWWDIR} \
		-DCMAKE_INSTALL_MANDIR=${PREFIX}/man \
		-DLOG_DIR=/var/log/hiawatha \
		-DPID_DIR=/var/run

OPTIONS_DEFINE=	CACHE DOCS IPV6 MONITOR RPROXY SSL TOMAHAWK TOOLKIT XSLT

OPTIONS_DEFAULT=	CACHE IPV6 RPROXY SSL TOOLKIT XSLT DOCS

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

PLIST_SUB+=	ECHO_MSG=${ECHO_MSG}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g' \
	${WRKSRC}/man/hiawatha.1.in ${WRKSRC}/man/cgi-wrapper.1.in \
	${WRKSRC}/config/cgi-wrapper.conf ${WRKSRC}/config/hiawatha.conf.in

	@${REINPLACE_CMD} -e 's|/etc/hiawatha|${ETCDIR}|g' \
	${WRKSRC}/man/hiawatha.1.in ${WRKSRC}/man/cgi-wrapper.1.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

.for FILE in ${CONFIG_FILES}
	@${INSTALL_DATA} ${WRKSRC}/config/${FILE} ${STAGEDIR}${PREFIX}/etc/hiawatha/${FILE}.sample
.endfor

	@${MKDIR} ${STAGEDIR}${WWWDIR} ; \
	${CP} ${WRKSRC}/extra/index.html ${STAGEDIR}${WWWDIR}/index.hiawatha.html

.include <bsd.port.mk>
