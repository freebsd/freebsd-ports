# $FreeBSD$

PORTNAME=	ZeGrapher
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.1.20200921
CATEGORIES=	math graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Software for plotting mathematical objects

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/boost/math/special_functions/binomial.hpp:devel/boost-libs

USES=		compiler:c++11-lang desktop-file-utils gl qmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	AdelKS
GH_TAGNAME=	6832bd61291b3e82bc05233ae74e8d7556abe910
USE_QT=		core gui network printsupport svg widgets buildtools_build
USE_GL=		gl

PLIST_FILES=	bin/${PORTNAME} \
		share/${PORTNAME}/locale/${PORTNAME}_fr.qm \
		share/applications/${PORTNAME}.desktop \
		share/icons/hicolor/128x128/apps/${PORTNAME}.png \
		share/metainfo/ZeGrapher.appdata.xml

PORTSCOUT=	limit:^[1-9].*

.include <bsd.port.mk>
