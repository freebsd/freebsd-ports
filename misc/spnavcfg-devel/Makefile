PORTNAME=	spnavcfg
PORTVERSION=	r${GIT_SRC_DATE}
CATEGORIES=	misc
PKGNAMESUFFIX=	-devel

MAINTAINER=	mr@freebsd.org
COMMENT=	Spacenav daemon interactive configuration program
WWW=	http://spacenav.sourceforge.net

LICENSE=	GPLv3+

LIB_DEPENDS+=	libspnav.so:misc/libspnav

USES=		gmake pkgconfig qt:6 xorg
USE_GITHUB=	yes
GH_ACCOUNT=	FreeSpacenav
GH_PROJECT=	spnavcfg
GH_TAGNAME=	${GIT_SRC_HASH}
USE_QT=		base svg tools
USE_XORG+=	x11
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug

ICONS=		devices.png spnavcfg-128x128.png spnavcfg-256x256.png spnavcfg-48x48.png spnavcfg.png
MAKE_ENV+=	MOC="${MOC}" RCC="${RCC}" UIC="${UIC}"
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/spnavcfg \
		share/applications/spnavcfg.desktop \
		share/icons/hicolor/128x128/apps/spnavcfg.png \
		share/icons/hicolor/256x256/apps/spnavcfg.png \
		share/icons/hicolor/48x48/apps/spnavcfg.png

.include	"Makefile.git_rev"

makeicons:
.for f in ${ICONS}
	(cd ${FILESDIR}/icons && uuencode -o ${f}.uu ${f} ${f})
.endfor

#${CP} ${FILESDIR}/icons/*.png ${WRKSRC}/icons/
#(cd ${WRKSRC} && uudecode ${FILESDIR}/burricons.png.uu)
#${f}
post-extract:
.for f in ${ICONS}
	(cd ${WRKSRC}/icons/ && uudecode ${FILESDIR}/icons/${f}.uu)
.endfor

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/spnavcfg

.include <bsd.port.mk>
