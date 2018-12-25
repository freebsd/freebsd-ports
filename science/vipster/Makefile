# $FreeBSD$

PORTNAME=	vipster
DISTVERSIONPREFIX=	v
DISTVERSION=	1.14a
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Crystalline and molecular structure visualisation program

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++17-lang
USE_GITHUB=	yes
GH_ACCOUNT=	sgsaenger
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		DESKTOP PYTHON
OPTIONS_DEFAULT=	DESKTOP
OPTIONS_SUB=		yes

DESKTOP_DESC=		Build QT-based desktop app
DESKTOP_CMAKE_BOOL=	DESKTOP
DESKTOP_USES=		qt:5
DESKTOP_USE=		QT=core,gui,widgets,buildtools_build,qmake_build

PYTHON_CMAKE_BOOL=	PYTHON
PYTHON_BROKEN=		Bundles pybind11: https://github.com/sgsaenger/vipster/issues/23

.include <bsd.port.mk>
