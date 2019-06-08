# $FreeBSD$

PORTNAME=	coyim
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.11
PORTREVISION=	2
CATEGORIES=	net-im

MAINTAINER=	santhosh.raju@gmail.com
COMMENT=	Safe and secure by default chat client

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go:lang/go
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		gnome pkgconfig shebangfix

USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 pango

SHEBANG_LANG=   sh
sh_OLD_CMD=     "/usr/bin/env bash"
sh_CMD=         /bin/sh
SHEBANG_FILES=  gen_version_file.sh

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

USE_GITHUB=	yes
GH_ACCOUNT=	coyim
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/${PORTNAME}

SUB_LIST=	PORTNAME=${PORTNAME}

PLIST_FILES=	bin/coyim \
		share/applications/coyim.desktop \
		share/pixmaps/coyim.png

GTK_VERSION=	"$$(pkg-config --modversion gtk+-3.0 | ${TR} . _ | cut -d '_' -f 1-2)"
GTK_BUILD_TAG=	gtk_${GTK_VERSION}

COYIM_ICON=		coyim.png
COYIM_ICON_SRC=		${WRKSRC}/build/mac-bundle/coy.iconset/icon_32x32@2x.png
COYIM_DESKTOP=		${WRKSRC}/build/coyim.desktop

INSTALLATION_DIRS+=	share/applications share/pixmaps

do-build:
	cd ${WRKSRC}/${GH_SUBDIR} && \
		./gen_version_file.sh ${DISTVERSIONPREFIX}${DISTVERSION} && \
		${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} \
		go build -tags ${GTK_BUILD_TAG} -o ${PORTNAME}

post-build:
	@${REINPLACE_CMD} -e '/^#/d' \
		-e '/^$$/d' \
		${COYIM_DESKTOP}
	${ECHO} "Exec=${PREFIX}/bin/coyim" >> ${COYIM_DESKTOP}
	${ECHO} "Icon=${COYIM_ICON}" >> ${COYIM_DESKTOP}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${COYIM_DESKTOP} ${STAGEDIR}${PREFIX}/share/applications/
	${INSTALL_DATA} ${COYIM_ICON_SRC} ${STAGEDIR}${PREFIX}/share/pixmaps/${COYIM_ICON}

.include <bsd.port.mk>
