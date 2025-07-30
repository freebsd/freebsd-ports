PORTNAME=	spnavcfg
PORTVERSION=	r${GIT_SRC_DATE}
#PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES+=	https://github.com/FreeSpacenav/spnavcfg/raw/refs/heads/master/icons/:icons
PKGNAMESUFFIX=	-devel
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${GH_ACCOUNT}-${PORTNAME}-${DISTVERSION}-${GH_TAGNAME}_GH0${EXTRACT_SUFX}

MAINTAINER=	mr@freebsd.org
COMMENT=	Spacenav daemon interactive configuration program
WWW=	http://spacenav.sourceforge.net

LICENSE=	GPLv3+

LIB_DEPENDS+=	libspnav.so:misc/libspnav

USES=		desktop-file-utils gmake pkgconfig qt:6 xorg
USE_GITHUB=	yes
GH_ACCOUNT=	FreeSpacenav
GH_PROJECT=	spnavcfg
GH_TAGNAME=	${GIT_SRC_HASH}
USE_QT=		base svg tools
USE_XORG+=	x11
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug

MAKE_ENV+=	MOC="${MOC}" RCC="${RCC}" UIC="${UIC}"
ALL_TARGET=	${PORTNAME}

ICONS=		devices.png spnavcfg-128x128.png spnavcfg-256x256.png spnavcfg-48x48.png spnavcfg.png
.for f in ${ICONS}
DISTFILES+=	$(f):icons
.endfor

PLIST_FILES=	bin/spnavcfg \
		share/applications/spnavcfg.desktop \
		share/icons/hicolor/128x128/apps/spnavcfg.png \
		share/icons/hicolor/256x256/apps/spnavcfg.png \
		share/icons/hicolor/48x48/apps/spnavcfg.png

.include	"Makefile.git_rev"

post-extract:
.for f in ${ICONS}
	(${CP} ${DISTDIR}/${DIST_SUBDIR}/${f} ${WRKSRC}/icons/${f})
.endfor

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/spnavcfg

.include <bsd.port.mk>
