PORTNAME=	color-widgets
DISTVERSION=	2.2.0
CATEGORIES=	x11-toolkits
PKGNAMESUFFIX=	${SUFFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Qt (C++) widgets to manage color inputs
WWW=		https://gitlab.com/mattia.basaglia/Qt-Color-Widgets

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang pkgconfig qt:5
USE_QT=		core gui widgets buildtools:build qmake:build
USE_LDCONFIG=	yes

SUFFIX=		-qt5

USE_GITLAB=	yes
GL_ACCOUNT=	mattia.basaglia
GL_PROJECT=	Qt-Color-Widgets
GL_TAGNAME=	f2eca13bbc836cec09daae02579f10d5e85e71e8

.include <bsd.port.mk>
