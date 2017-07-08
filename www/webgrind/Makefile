# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	webgrind
PORTVERSION=	1.5.0
DISTVERSIONPREFIX=v
CATEGORIES=	www

MAINTAINER=	franco@opnsense.org
COMMENT=	Xdebug Profiling Web Frontend in PHP

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

MAKEFILE=	${WRKSRC}/makefile

OPTIONS_DEFINE=	CALLGRAPH

USE_GITHUB=	yes
GH_ACCOUNT=	jokkedk

USES=		php

PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"

CALLGRAPH_USES=		python
CALLGRAPH_RUN_DEPENDS=	dot:graphics/graphviz

CALLGRAPH_DESC=		Enable call graph

post-patch-CALLGRAPH-on:
	@${REINPLACE_CMD} -e 's,/usr/bin/python,${PYTHON_CMD},' ${WRKSRC}/config.php
	@${REINPLACE_CMD} -e 's,/usr/bin/dot,/usr/local/bin/dot,' ${WRKSRC}/config.php

do-install:
	@${RM} ${WRKSRC}/library/preprocessor.cpp ${WRKSRC}/makefile
	@${MKDIR} ${STAGEDIR}${WWWDIR}/bin
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "*" ${STAGEDIR}${WWWDIR} \
		'! -name license.txt ! -name package.sh')
	${INSTALL_PROGRAM} ${WRKSRC}/bin/preprocessor ${STAGEDIR}${WWWDIR}/bin

.include <bsd.port.mk>
