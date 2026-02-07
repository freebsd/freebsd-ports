PORTNAME=	makenl
DISTVERSION=	3.5.1
CATEGORIES=	net-mgmt

MAINTAINER=	dz@dolik.dev
COMMENT=	FidoNet NodeList Generator Program
WWW=		https://github.com/zoomosis/makenl

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/docs/license.txt

USES=		cmake

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_SUB=	yes

DOCS_CMAKE_BOOL=	DOCS
EXAMPLES_CMAKE_BOOL=	EXAMPLES

USE_GITHUB=	yes
GH_ACCOUNT=	zoomosis
GH_TAGNAME=	ab7babe

.include <bsd.port.mk>
