PORTNAME=	ZeGrapher
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.1.20250115
CATEGORIES=	math graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Software for plotting mathematical objects
WWW=		https://zegrapher.com/en/ \
		https://github.com/AdelKS/ZeGrapher

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/boost/math/special_functions/binomial.hpp:devel/boost-libs

USES=		cmake:indirect compiler:c++11-lang desktop-file-utils gl meson pkgconfig qt:6
USE_QT=		base declarative svg tools:build
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	AdelKS
GH_TAGNAME=	d574a39
GH_TUPLE=	AdelKS:ZeCalculator:v0.11.1:ZeCalculator/subprojects/zecalculator

PLIST_FILES=	bin/${PORTNAME}

PORTSCOUT=	limit:^[1-9].*

.include <bsd.port.mk>
