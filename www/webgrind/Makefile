# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	webgrind
DISTVERSION=	1.0.s${SNAPSHOT}
CATEGORIES=	www

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Xdebug Profiling Web Frontend in PHP

LICENSE=	BSD3CLAUSE

OPTIONS_DEFINE=	CALLGRAPH

USE_GITHUB=	yes
GH_ACCOUNT=	jokkedk
GH_TAGNAME=	${GH_COMMIT}

SNAPSHOT=	20140207
GH_COMMIT=	dc35393

USE_PHP=	yes

NO_BUILD=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCALLGRAPH}
USE_PYTHON=	yes
RUN_DEPENDS+=	dot:${PORTSDIR}/graphics/graphviz
.endif

post-patch:
	${REINPLACE_CMD} -e 's,/usr/bin/python,/usr/local/bin/python,' ${WRKSRC}/config.php

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "*" ${STAGEDIR}${WWWDIR} "! -name *.bak")

	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${WWWDIR}
	@${FIND} ${STAGEDIR}${WWWDIR} -type f -exec ${CHMOD} 0444 {} \;
	@${FIND} ${STAGEDIR}${WWWDIR} -type d -exec ${CHMOD} 0755 {} \;

.include <bsd.port.mk>
