PORTNAME=	unison
PORTVERSION=	2.51.5
PORTREVISION=	3
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	User-level file synchronization tool
WWW=		https://www.cis.upenn.edu/~bcpierce/unison/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

FLAVORS=	x11 nox11
FLAVOR?=	${FLAVORS:[1]}

VERSIONSUFFIX=	251

nox11_PKGNAMESUFFIX=		${VERSIONSUFFIX}-nox11
nox11_CONFLICTS_INSTALL=	unison${VERSIONSUFFIX}

x11_PKGNAMESUFFIX=	${VERSIONSUFFIX}
x11_BUILD_DEPENDS=	icotool:graphics/icoutils \
			lablgtk2:x11-toolkits/ocaml-lablgtk2
x11_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2 \
			libharfbuzz.so:print/harfbuzz
x11_CONFLICTS_INSTALL=	unison${VERSIONSUFFIX}-nox11

USES=		gmake localbase ocaml:build
USE_GITHUB=	yes
GH_ACCOUNT=	bcpierce00

MAKE_ENV=	CLIBS="${LIBS:S/^-/-ccopt -/}" \
		COFLAGS="${CFLAGS:C/ *(-[^ ]*) */ -ccopt \"\1 \"/gW}"
ALL_TARGET=	unison all

DOCS=		NEWS README

WRKSRC_SUBDIR=	src

PLIST_SUB=	PORTVERSION=${PORTVERSION} \
		VERSIONSUFFIX=${VERSIONSUFFIX}

OPTIONS_DEFINE=		DOCS FSMONITOR
OPTIONS_DEFAULT=	FSMONITOR
OPTIONS_SUB=		YES

FSMONITOR_DESC=	Compile and install fsmonitor plugin

FSMONITOR_LIB_DEPENDS=	libinotify.so:devel/libinotify

.if ${FLAVOR} == nox11
MAKE_ARGS=	UISTYLE=text
PKGMESSAGE=	${PKGDIR}/pkg-message.nox11
PLIST_SUB+=	X11="@comment "
.else
MAKE_ARGS=	UISTYLE=gtk2
SUB_FILES=	${PORTNAME}.desktop
USE_GNOME+=	atk cairo gdkpixbuf glib20 gtk20 pango
USES+=		gettext-runtime gnome
PLIST_SUB+=	X11=""
.endif

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USE_BINUTILS=	yes
.endif

post-patch-FSMONITOR-off:
	@${REINPLACE_CMD} -e 's/-include fsmonitor/#&/' \
		${WRKSRC}/Makefile.OCaml

post-patch-FSMONITOR-on:
	@${REINPLACE_CMD} \
		-e '/let suffix = if Util.osType/s/else "" in/else "${VERSIONSUFFIX}" in/' \
		${WRKSRC}/fswatch.ml

post-patch:
.if ${FLAVOR} == nox11
	@${REINPLACE_CMD} -e 's/CFLAGS/COFLAGS/g' \
		${WRKSRC}/Makefile.OCaml ${WRKSRC}/fsmonitor/linux/Makefile
.else
	@${REINPLACE_CMD} -Ee 's@(\+|/)(lablgtk2)@\1site-lib/\2@' \
		-e 's/CFLAGS/COFLAGS/g' \
		${WRKSRC}/Makefile.OCaml ${WRKSRC}/fsmonitor/linux/Makefile
.endif

post-build:
	(cd ${WRKSRC} && HOME=${WRKSRC} ./unison -selftest -ui text -batch)
.if ${FLAVOR} == x11
	@${ECHO} Building text-only version
	@${ECHO} ${WRKSRC}
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} -C ${WRKSRC} UISTYLE=text NAME=unison-text
	@cd ${WRKSRC}/win32rc && ${LOCALBASE}/bin/icotool -x U.ico
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}${VERSIONSUFFIX}
.if ${FLAVOR} == x11
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}-text ${STAGEDIR}${PREFIX}/bin/${PORTNAME}${VERSIONSUFFIX}-text
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}/${PORTNAME}${VERSIONSUFFIX}.desktop
	${INSTALL_DATA} ${WRKSRC}/win32rc/U_4_48x48x32.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}${VERSIONSUFFIX}.png
.endif

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

do-install-FSMONITOR-on:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}-fsmonitor ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-fsmonitor${VERSIONSUFFIX}

.include <bsd.port.mk>
