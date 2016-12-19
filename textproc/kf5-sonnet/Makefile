# Created by: tcberner
# $FreeBSD$

PORTNAME=	sonnet
PORTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	textproc kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 plugin-based spell checking library

LIB_DEPENDS=	libaspell.so:textproc/aspell \
		libhunspell-1.5.so:textproc/hunspell

USES=		cmake:outsource compiler:c++11-lib kde:5 tar:xz
USE_KDE=	ecm
USE_QT5=	buildtools_build core gui linguisttools qmake_build \
		testlib widgets

.include <bsd.port.mk>
