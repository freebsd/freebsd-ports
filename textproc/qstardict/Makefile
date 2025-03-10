PORTNAME=	qstardict
DISTVERSION=	3.0.0
CATEGORIES=	textproc
MASTER_SITES=	https://qstardict.ylsoftware.com/files/

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	Qt based dictionary program (stardict clone)
WWW=		https://qstardict.ylsoftware.com/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++17-lang gettext gl gnome pkgconfig qmake qt:6 xorg
USE_GL=		opengl
USE_GNOME=	glib20
USE_QT=		base tools:build
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
