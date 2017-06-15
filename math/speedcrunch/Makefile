# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	speedcrunch
DISTVERSION=	0.11
CATEGORIES=	math

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Keyboard-oriented desktop scientific calculator

LICENSE=	GPLv2+

USE_GITHUB=	yes
GH_PROJECT=	SpeedCrunch

USES=		cmake:outsource
CMAKE_SOURCE_PATH=	${WRKSRC}/src
USE_QT4=	qmake_build moc_build rcc_build uic_build corelib gui network
USE_XORG=	x11 xext sm ice

.include <bsd.port.mk>
