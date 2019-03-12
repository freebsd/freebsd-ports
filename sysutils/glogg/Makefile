# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	glogg
DISTVERSION=	1.1.4
PORTREVISION=	5
CATEGORIES=	sysutils textproc
MASTER_SITES=	http://glogg.bonnefon.org/files/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	GUI application to browse and search through long or complex log files

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs

USES=		compiler:c++11-lang desktop-file-utils qmake qt:5
USE_QT=		core gui widgets dbus buildtools_build
LDFLAGS+=	-Wl,--as-needed  # prevents stray USE_GL=gl, see bug#224488

PLIST_FILES=	bin/glogg \
		share/applications/glogg.desktop \
		share/icons/hicolor/16x16/apps/glogg.png \
		share/icons/hicolor/32x32/apps/glogg.png \
		share/icons/hicolor/scalable/apps/glogg.svg

.include <bsd.port.mk>
