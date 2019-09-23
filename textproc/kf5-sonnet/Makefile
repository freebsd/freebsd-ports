# $FreeBSD$

PORTNAME=	sonnet
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	textproc kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 plugin-based spell checking library

LIB_DEPENDS=	libaspell.so:textproc/aspell \
		libhunspell-1.7.so:textproc/hunspell

USES=		cmake compiler:c++11-lib kde:5 qt:5 tar:xz
USE_KDE=	ecm
USE_QT=		core gui linguisttools testlib uiplugin widgets \
		buildtools_build qmake_build

# Disable examples -- they are not installed anyways.
CMAKE_OFF=	ENABLE_EXAMPLES

.include <bsd.port.mk>
