# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	protovis
PORTVERSION=	3.2
CATEGORIES=	www
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JavaScript graphical toolkit for data visualization

NO_BUILD=	yes
USE_ZIP=	yes

PROJECTHOST=	${PORTNAME}-js

do-install:
	${MKDIR} ${DOCSDIR}/ ${EXAMPLESDOR}/ ${WWWDIR}/
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/jsdoc/ && ${COPYTREE_SHARE} '*' ${DOCSDIR}/
.endif
.if !defined(NOPORTEXAMPLES)
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} '*' ${EXAMPLESDIR}/
.endif
	cd ${WRKSRC}/ && ${INSTALL_DATA} -o ${WWWOWN} -g ${WWWGRP} *.js ${WWWDIR}/

.include <bsd.port.mk>
