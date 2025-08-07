PORTNAME=	coyim
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.1
PORTREVISION=	3
CATEGORIES=	net-im

MAINTAINER=	fox@FreeBSD.org
COMMENT=	Safe and secure by default XMPP chat client which uses Tor
WWW=		https://coy.im

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		gnome go pkgconfig
USE_GNOME=	atk cairo gdkpixbuf glib20 gtk30 pango
USE_GITHUB=	yes
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/${PORTNAME}

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

GO_BUILDFLAGS=	-tags ${GTK_BUILD_TAG}

SUB_LIST=	PORTNAME=${PORTNAME}

PLIST_FILES=	bin/coyim \
		share/applications/coyim.desktop \
		share/pixmaps/coyim.png

GTK_VERSION=	"$$(pkg-config --modversion gtk+-3.0 | ${TR} . _ | cut -d '_' -f 1-2)"
GTK_BUILD_TAG=	gtk_${GTK_VERSION}

COYIM_ICON=	coyim.png
COYIM_ICON_SRC=	${WRKSRC}/build/osx/mac-bundle/coyim.iconset/icon_32x32@2x.png
COYIM_DESKTOP=	${WRKDIR}/coyim.desktop

post-extract:
	cd ${WRKSRC} && ${RM} ./windows_amd64_icon.syso
	cp ${FILESDIR}/coyim.desktop ${WRKDIR}

post-build:
	@${REINPLACE_CMD} -e '/^#/d' \
		-e '/^$$/d' \
		${COYIM_DESKTOP}
	${ECHO_CMD} "Exec=${PREFIX}/bin/coyim" >> ${COYIM_DESKTOP}
	${ECHO_CMD} "Icon=${COYIM_ICON}" >> ${COYIM_DESKTOP}

post-install:
	${INSTALL_DATA} ${COYIM_DESKTOP} ${STAGEDIR}${PREFIX}/share/applications/
	${INSTALL_DATA} ${COYIM_ICON_SRC} ${STAGEDIR}${PREFIX}/share/pixmaps/${COYIM_ICON}

.include <bsd.port.mk>
