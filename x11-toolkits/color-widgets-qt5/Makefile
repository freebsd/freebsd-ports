# $FreeBSD$

PORTNAME=	color-widgets
DISTVERSION=	2.2.0
CATEGORIES=	x11-toolkits
PKGNAMESUFFIX=	${SUFFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Qt (C++) widgets to manage color inputs

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang pkgconfig qt:5
USE_QT=		core gui widgets buildtools_build qmake_build
USE_LDCONFIG=	yes

SUFFIX=		-qt5

USE_GITLAB=	yes
GL_ACCOUNT=	mattia.basaglia
GL_PROJECT=	Qt-Color-Widgets
GL_COMMIT=	f2eca13bbc836cec09daae02579f10d5e85e71e8

.include <bsd.port.mk>
