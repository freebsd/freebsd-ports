PORTNAME=	unison
PORTVERSION=	2.53.4
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	User-level file synchronization tool
WWW=		https://www.cis.upenn.edu/~bcpierce/unison/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

FLAVORS=	x11 nox11
FLAVOR?=	${FLAVORS:[1]}

nox11_PKGNAMESUFFIX=		-nox11
nox11_CONFLICTS_INSTALL=	unison

x11_BUILD_DEPENDS=	icotool:graphics/icoutils \
			ocaml-lablgtk3>0:x11-toolkits/ocaml-lablgtk3
x11_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2 \
			libharfbuzz.so:print/harfbuzz
x11_CONFLICTS_INSTALL=	unison-nox11

USES=		gmake localbase
USE_GITHUB=	yes
GH_ACCOUNT=	bcpierce00
USE_OCAML=	yes

NO_OCAML_RUNDEPENDS=	yes
MAKE_ENV=	CLIBS="${LIBS:S/^-/-ccopt -/}" \
		COFLAGS="${CFLAGS:C/ *(-[^ ]*) */ -ccopt \"\1 \"/gW}"
WRKSRC_SUBDIR=	src
PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=		DOCS FSMONITOR
OPTIONS_DEFAULT?=	FSMONITOR
OPTIONS_SUB=		YES

FSMONITOR_DESC=	Compile and install fsmonitor plugin

DOCS_USES=	tex
DOCS_USE=	TEX=dvipsk:build,latex:build

FSMONITOR_LIB_DEPENDS=	libinotify.so:devel/libinotify

.if ${FLAVOR} == nox11
ALL_TARGET=	tui
PKGMESSAGE=	${PKGDIR}/pkg-message.nox11
PLIST_SUB+=	X11="@comment "
.else
ALL_TARGET=	tui guimaybe
SUB_FILES=	${PORTNAME}.desktop
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 pango
USES+=		gettext-runtime gnome
PLIST_SUB+=	X11=""
.endif

DOCS=		NEWS.md README.md

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFSMONITOR}
ALL_TARGET+=	fsmonitor
.endif

post-build:
	cd ${WRKSRC} && HOME=${WRKSRC} ./unison -selftest -ui text -batch
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} -C ${WRKSRC}/../man
.if ${PORT_OPTIONS:MDOCS}
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} -C ${WRKSRC}/../doc unison-manual.pdf
.endif
.if ${FLAVOR} == x11
	cd ${WRKSRC}/win32rc && ${LOCALBASE}/bin/icotool -x U.ico
.endif

do-install:
.if ${FLAVOR} == nox11
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
.else
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}-gui ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-text
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/win32rc/U_4_48x48x32.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
.endif
	${INSTALL_MAN} ${WRKSRC}/../man/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/.. && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/../doc && ${INSTALL_DATA} unison-manual.pdf ${STAGEDIR}${DOCSDIR}

do-install-FSMONITOR-on:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}-fsmonitor ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
