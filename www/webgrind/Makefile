PORTNAME=	webgrind
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.2
CATEGORIES=	www

MAINTAINER=	franco@opnsense.org
COMMENT=	Xdebug Profiling Web Frontend in PHP

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		cpe php
CPE_VENDOR=	webgrind_project
USE_GITHUB=	yes
GH_ACCOUNT=	jokkedk

MAKEFILE=	${WRKSRC}/makefile

PLIST_SUB=	WWWGRP="${WWWGRP}" \
		WWWOWN="${WWWOWN}"

OPTIONS_DEFINE=	CALLGRAPH

CALLGRAPH_DESC=	Enable call graph

CALLGRAPH_RUN_DEPENDS=	dot:graphics/graphviz
CALLGRAPH_USES=		python

post-patch-CALLGRAPH-on:
	@${REINPLACE_CMD} -e 's,/usr/bin/python3,${PYTHON_CMD},' ${WRKSRC}/config.php
	@${REINPLACE_CMD} -e 's,/usr/bin/dot,/usr/local/bin/dot,' ${WRKSRC}/config.php

do-install:
	@${RM} ${WRKSRC}/library/preprocessor.cpp ${WRKSRC}/makefile
	@${MKDIR} ${STAGEDIR}${WWWDIR}/bin
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "*" ${STAGEDIR}${WWWDIR} \
		'! -name license.txt ! -name package.sh')
	${INSTALL_PROGRAM} ${WRKSRC}/bin/preprocessor ${STAGEDIR}${WWWDIR}/bin

.include <bsd.port.mk>
