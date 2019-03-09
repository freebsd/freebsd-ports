# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	qstardict
DISTVERSIONPREFIX=	qstardict-
DISTVERSION=	1.3
CATEGORIES=	textproc
MASTER_SITES=	http://qstardict.ylsoftware.com/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt based dictionary program (stardict clone)

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gl gnome pkgconfig qmake qt:5 tar:bzip2
USE_GL=		gl
USE_GNOME=	glib20
USE_QT=		core dbus gui network printsupport widgets xml \
		buildtools_build linguisttools_build qmake_build
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	a-rodin

QMAKE_ARGS=	INSTALL_PREFIX=${PREFIX}

OPTIONS_DEFINE=	DOCS

# Path to dictionaries installed by stardict-* ports
DICPATH=	${LOCALBASE}/share/stardict/dic

post-patch:
	${REINPLACE_CMD} '/m_dictDirs/s|/usr/share/stardict/dic|${PREFIX}/share/stardict/dic|g' \
		${WRKSRC}/plugins/stardict/stardict.cpp

.include <bsd.port.mk>
