# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	speedcrunch
DISTVERSION=	0.11
CATEGORIES=	math
MASTER_SITES=	GITHUB

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Keyboard-oriented desktop scientific calculator

USE_QT4=	qmake_build moc_build rcc_build uic_build gui network
USES=		cmake:outsource
CMAKE_SOURCE_PATH=	${WRKSRC}/src

USE_GITHUB=	yes
GH_ACCOUNT=	speedcrunch
GH_PROJECT=	SpeedCrunch
GH_COMMIT=	90d56d1

pre-configure:
	${REINPLACE_CMD} -e '/CMAKE_COLOR_MAKEFILE/d' \
			-e '/CMAKE_VERBOSE_MAKEFILE/d' \
			${WRKSRC}/src/CMakeLists.txt

.include <bsd.port.mk>
