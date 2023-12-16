PORTNAME=	qstardict
DISTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	https://qstardict.ylsoftware.com/files/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Qt based dictionary program (stardict clone)
WWW=		https://qstardict.ylsoftware.com/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libzim.so:devel/libzim

USES=		compiler:c++17-lang gl gnome pkgconfig qmake qt:5 xorg
USE_GL=		gl
USE_GNOME=	glib20
USE_QT=		core dbus gui network printsupport widgets xml \
		buildtools:build linguisttools:build qmake:build
USE_XORG=	x11

QMAKE_ARGS=	INSTALL_PREFIX=${PREFIX}

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

# Path to dictionaries installed by stardict-* ports
DICPATH=	${LOCALBASE}/share/stardict/dic

post-patch:
	${REINPLACE_CMD} '/m_dictDirs/s|/usr/share/stardict/dic|${PREFIX}/share/stardict/dic|g' \
		${WRKSRC}/plugins/stardict/stardict.cpp

.include <bsd.port.mk>
