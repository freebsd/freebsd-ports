# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	protovis
PORTVERSION=	3.3.1
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JavaScript graphical toolkit for data visualization

LICENSE=	BSD3CLAUSE

OPTIONS_DEFINE=	EXAMPLES

PORTSCOUT=	limit:^v[0-9\.]*$$

NO_ARCH=	yes
NO_BUILD=	yes

PORTEXAMPLES=	*

GH_ACCOUNT=	mbostock
USE_GITHUB=	yes

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} *.js ${STAGEDIR}${WWWDIR}/

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
