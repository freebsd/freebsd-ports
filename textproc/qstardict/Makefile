# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	qstardict
DISTVERSIONPREFIX=	qstardict-
DISTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Qt based dictionary program (stardict clone)

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lang gl gnome pkgconfig qmake qt:5 tar:bzip2 xorg
USE_GL=		gl
USE_GNOME=	glib20
USE_QT=		core dbus gui network printsupport widgets xml \
		buildtools_build linguisttools_build qmake_build
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	a-rodin

QMAKE_ARGS=	INSTALL_PREFIX=${PREFIX}

OPTIONS_DEFINE=	DOCS KDE
OPTIONS_SUB=	yes

KDE_DESC=	KDE integration
KDE_USES=	kde:5
KDE_USE=	KDE=globalaccel,notifications,windowsystem
KDE_QMAKE_ON=	"ENABLED_PLUGINS=stardict web kdeintegration"

# Path to dictionaries installed by stardict-* ports
DICPATH=	${LOCALBASE}/share/stardict/dic

post-patch:
	${REINPLACE_CMD} '/m_dictDirs/s|/usr/share/stardict/dic|${PREFIX}/share/stardict/dic|g' \
		${WRKSRC}/plugins/stardict/stardict.cpp

.include <bsd.port.mk>
