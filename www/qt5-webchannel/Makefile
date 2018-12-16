# $FreeBSD$

PORTNAME=	webchannel
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	www
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 5 library for integration of C++/QML with HTML/js clients

USES=		compiler:c++11-lang qmake:norecursive qt-dist:5,webchannel
USE_QT=		buildtools_build core declarative
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

# The default EXTRACT_AFTER_ARGS value excludes examples/ from the extracted
# tarball, which we need during the build.
EXTRACT_AFTER_ARGS=	--no-same-owner --no-same-permissions

.include <bsd.port.mk>
