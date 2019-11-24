# Created by: Dan Pelleg <dpelleg+unison@cs.cmu.edu>
# $FreeBSD$

PORTNAME=	unison
PORTVERSION=	2.51.2
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	User-level file synchronization tool

LICENSE=	GPLv3

FLAVORS=	x11 nox11
FLAVOR?=	${FLAVORS:[1]}

nox11_PKGNAMESUFFIX= -nox11
nox11_CONFLICTS_INSTALL=	unison

x11_CONFLICTS_INSTALL=		unison-nox11
x11_BUILD_DEPENDS=	lablgtk2:x11-toolkits/ocaml-lablgtk2 \
			icotool:graphics/icoutils
x11_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2
x11_RUN_DEPENDS=	lablgtk2:x11-toolkits/ocaml-lablgtk2

PLIST_SUB=	PORTVERSION=${PORTVERSION}
USES=		gmake localbase
USE_OCAML=	yes
WRKSRC_SUBDIR=	src
NO_OCAML_RUNDEPENDS=yes
CONFLICTS=	unison-devel-[0-9]*
MAKE_ENV=	CLIBS="${LIBS:S/^-/-ccopt -/}" COFLAGS="${CFLAGS:C/ *(-[^ ]*) */ -ccopt \"\1 \"/gW}"
MAKE_JOBS_UNSAFE=	yes
ALL_TARGET=	unison all

USE_GITHUB=     yes
GH_ACCOUNT=     bcpierce00

DOCS=		BUGS.txt NEWS README

OPTIONS_DEFINE=		DOCS FSMONITOR
OPTIONS_DEFAULT?=	FSMONITOR

FSMONITOR_DESC=		Compile and install fsmonitor plugin

OPTIONS_SUB=		YES

FSMONITOR_LIB_DEPENDS=	libinotify.so:devel/libinotify

.if ${FLAVOR} == nox11
MAKE_ARGS=		UISTYLE=text
PKGMESSAGE=		${PKGDIR}/pkg-message.nox11
PLIST_SUB+=		X11="@comment "
.else
MAKE_ARGS=		UISTYLE=gtk2
SUB_FILES=		${PORTNAME}.desktop
USE_GNOME+=		atk cairo gdkpixbuf2 glib20 gtk20 pango
USES+=			gettext-runtime gnome
PLIST_SUB+=		X11=""
.endif

post-patch-FSMONITOR-off:
	@${REINPLACE_CMD} -e 's/-include fsmonitor/#&/' \
		${WRKSRC}/Makefile.OCaml

post-patch:
.if ${FLAVOR} == nox11
	@${REINPLACE_CMD} -e 's/CFLAGS/COFLAGS/g' \
		${WRKSRC}/Makefile.OCaml ${WRKSRC}/fsmonitor/linux/Makefile
.else
	@${REINPLACE_CMD} -Ee 's@(\+|/)(lablgtk2)@\1site-lib/\2@' \
		-e 's/CFLAGS/COFLAGS/g' \
		${WRKSRC}/Makefile.OCaml ${WRKSRC}/fsmonitor/linux/Makefile
.endif

.if ${FLAVOR} == x11
post-build:
	@${ECHO} Building text-only version
	@${ECHO} ${WRKSRC}
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} -C ${WRKSRC} UISTYLE=text NAME=unison-text
	@cd ${WRKSRC}/win32rc && ${LOCALBASE}/bin/icotool -x U.ico
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}
.if ${FLAVOR} == x11
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}-text ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/win32rc/U_4_48x48x32.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
.endif

do-install-FSMONITOR-on:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}-fsmonitor ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
