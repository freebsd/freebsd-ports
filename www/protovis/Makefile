# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	protovis
PORTVERSION=	3.3.1
CATEGORIES=	www

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JavaScript graphical toolkit for data visualization

LICENSE=	BSD3CLAUSE

OPTIONS_DEFINE=	EXAMPLES

NO_BUILD=	yes

PORTEXAMPLES=	*

GH_ACCOUNT=	mbostock
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	v${PORTVERSION}
USE_GITHUB=	yes

do-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/ ${STAGEDIR}${WWWDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} *.js ${STAGEDIR}${WWWDIR}/
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
