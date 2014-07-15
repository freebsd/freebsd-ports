# Created by: Hsin-Han You <hhyou@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	phpweathermap
PORTVERSION=	0.97a
PORTREVISION=	1
CATEGORIES=	net-mgmt www
MASTER_SITES=	http://www.network-weathermap.com/files/
DISTNAME=	php-weathermap-${PORTVERSION}

MAINTAINER=	hhyou@cs.nctu.edu.tw
COMMENT=	Network visualisation tool with web editor

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/share/pear/Console/Getopt.php:${PORTSDIR}/devel/pear \
		rrdtool:${PORTSDIR}/databases/rrdtool

NO_BUILD=	yes
USES=		zip
USE_PHP=	gd

WM_FILES=	HTML_ImageMap.class.php WeatherMap.functions.php \
		WeatherMapLink.class.php WeatherMapNode.class.php \
		Weathermap.class.php weathermap.conf

WM_WWW_FILES=	overlib.js editor-config.php-dist editor.css \
		editor.inc.php editor.js editor.php

WM_WWW_DIRS=	editor-resources images docs

PORTDOCS=	CHANGES COPYING README
WRKSRC=		${WRKDIR}/weathermap

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>
post-patch:
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' ${WRKSRC}/editor.php
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' \
			    -e 's|%%PREFIX%%|${PREFIX}|'  ${WRKSRC}/weathermap

do-install:
	@${MKDIR} ${STAGEDIR}/${DATADIR}/www/configs
	@${INSTALL_SCRIPT} ${WRKSRC}/weathermap ${STAGEDIR}/${PREFIX}/bin/phpweathermap
	@for i in ${WM_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${STAGEDIR}/${DATADIR}/$$i; \
	done
	@for i in ${WM_WWW_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${STAGEDIR}/${DATADIR}/www/$$i; \
	done
	@${CP} -R ${WRKSRC}/lib ${STAGEDIR}/${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "${WM_WWW_DIRS}" ${STAGEDIR}/${DATADIR}/www)
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}/${DATADIR}/www

.if ${PORT_OPTIONS:MEXAMPLES}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "random-bits" ${STAGEDIR}/${EXAMPLESDIR})
	@${FIND} ${STAGEDIR}/${EXAMPLESDIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 644
	@${FIND} ${STAGEDIR}/${EXAMPLESDIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}/${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
