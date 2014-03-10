# Created by: Hsin-Han You <hhyou@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	phpweathermap
PORTVERSION=	0.97a
PORTREVISION=	1
CATEGORIES=	net-mgmt www
MASTER_SITES=	http://www.network-weathermap.com/files/
DISTNAME=	php-weathermap-${PORTVERSION}

MAINTAINER=	hhyou@cs.nctu.edu.tw
COMMENT=	A network visualisation tool with web editor

RUN_DEPENDS=	${LOCALBASE}/share/pear/Console/Getopt.php:${PORTSDIR}/devel/pear \
		rrdtool:${PORTSDIR}/databases/rrdtool

NO_BUILD=	yes
USES=		zip
USE_PHP=	gd

LICENSE=	GPLv2

WM_FILES=	HTML_ImageMap.class.php WeatherMap.functions.php \
		WeatherMapLink.class.php WeatherMapNode.class.php \
		Weathermap.class.php weathermap.conf

WM_WWW_FILES=	overlib.js editor-config.php-dist editor.css \
		editor.inc.php editor.js editor.php

WM_WWW_DIRS=	editor-resources images docs

PORTDOCS=	CHANGES COPYING README
WRKSRC=		${WRKDIR}/weathermap

SUB_FILES=	pkg-message

NO_STAGE=	yes
.include <bsd.port.pre.mk>
post-patch:
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' ${WRKSRC}/editor.php
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' \
			    -e 's|%%PREFIX%%|${PREFIX}|'  ${WRKSRC}/weathermap
# 	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' ${WRKSRC}/editor.php

do-install:
	@${MKDIR} ${DATADIR}/www/configs
	@${INSTALL_SCRIPT} ${WRKSRC}/weathermap ${PREFIX}/bin/phpweathermap
	@for i in ${WM_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${DATADIR}/$$i; \
	done
	@for i in ${WM_WWW_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${DATADIR}/www/$$i; \
	done
	@${CP} -R ${WRKSRC}/lib ${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "${WM_WWW_DIRS}" ${DATADIR}/www)
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${DATADIR}/www
.if !defined(NOPORTEXAMPLES)
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "random-bits" ${EXAMPLESDIR})
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} \
		${EXAMPLESDIR:S|^${PREFIX}/|%D/|}' >> ${TMPPLIST}
	@${FIND} ${EXAMPLESDIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 644
	@${ECHO_CMD} '@exec ${FIND} ${EXAMPLESDIR} -type f -print0 | \
		${XARGS} -0 ${CHMOD} 644' >> ${TMPPLIST}
	@${FIND} ${EXAMPLESDIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@${ECHO_CMD} '@exec ${FIND} ${EXAMPLESDIR} -type d -print0 | \
		${XARGS} -0 ${CHMOD} 755' >> ${TMPPLIST}
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
