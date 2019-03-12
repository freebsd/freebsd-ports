# $FreeBSD$

PORTNAME=	ZeGrapher
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.2
PORTREVISION=	4
CATEGORIES=	math graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Software for plotting mathematical objects

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/boost/math/special_functions/binomial.hpp:devel/boost-libs

USES=		compiler:c++11-lang desktop-file-utils qmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	AdelKS
USE_QT=		core gui network printsupport widgets buildtools_build
USE_GL=		gl

PLIST_FILES=	bin/${PORTNAME} \
		share/${PORTNAME}/locale/${PORTNAME}_fr.qm \
		share/appdata/${PORTNAME}.appdata.xml \
		share/applications/${PORTNAME}.desktop \
		share/icons/hicolor/128x128/apps/${PORTNAME}.png

.include <bsd.port.mk>
