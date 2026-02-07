PORTNAME=	qstardict
DISTVERSION=	4.0.0
CATEGORIES=	textproc
MASTER_SITES=	https://qstardict.ylsoftware.com/files/

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	Qt based dictionary program (stardict clone)
WWW=		https://qstardict.ylsoftware.com/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c++17-lang gettext-runtime gl gnome pkgconfig qmake \
		qt:6 xorg
USE_GL=		opengl
USE_GNOME=	glib20
USE_QT=		base tools:build
USE_XORG=	x11

QMAKE_ARGS=	INSTALL_PREFIX=${PREFIX}

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

# Path to dictionaries installed by stardict-* ports
DICPATH=	share/stardict/dic

post-patch:
	@${REINPLACE_CMD} '/${DICPATH:S/\//\\\//g}/s|/usr|${PREFIX}|' \
		${WRKSRC}/plugins/stardict/stardict.cpp
	@${REINPLACE_CMD} '/VERSION = /s/3\.0\.0/${DISTVERSION}/' \
		${WRKSRC}/qstardict.pri

.include <bsd.port.mk>
