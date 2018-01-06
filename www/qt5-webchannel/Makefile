# $FreeBSD$

PORTNAME=	webchannel
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	www
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 5 library for integration of C++/QML with HTML/js clients

USE_QT5=	buildtools_build core qml quick
QT_DIST=	${PORTNAME}
USES=		qmake:norecursive
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

# The default EXTRACT_AFTER_ARGS value excludes examples/ from the extracted
# tarball, which we need during the build.
EXTRACT_AFTER_ARGS=	# empty

.include <bsd.port.mk>
