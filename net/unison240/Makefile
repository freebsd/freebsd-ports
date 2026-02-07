PORTNAME=	unison
PORTVERSION=	2.40.128
PORTREVISION=	8
CATEGORIES=	net

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	User-level file synchronization tool
WWW=		https://www.cis.upenn.edu/~bcpierce/unison/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

VERSIONSUFFIX=	240

DEPRECATED=	Legacy release unsupported by upstream
EXPIRATION_DATE=	2026-02-28

FLAVORS=	x11 nox11
FLAVOR?=	${FLAVORS:[1]}

nox11_PKGNAMESUFFIX=		${VERSIONSUFFIX}-nox11
nox11_CONFLICTS_INSTALL=	unison${VERSIONSUFFIX}

x11_PKGNAMESUFFIX=	${VERSIONSUFFIX}
x11_BUILD_DEPENDS=	icotool:graphics/icoutils \
			lablgtk2:x11-toolkits/ocaml-lablgtk2
x11_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2
x11_CONFLICTS_INSTALL=	unison${VERSIONSUFFIX}-nox11
USES=			gmake ocaml:build
USE_GITHUB=		yes
GH_ACCOUNT=		bcpierce00
GH_TAGNAME=		2.40

MAKE_ARGS=	CFLAGS=""
ALL_TARGET=	unison all
TEST_TARGET=	selftest

DOCS=		BUGS.txt NEWS README
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

WRKSRC_SUBDIR=	src

PLIST_SUB=	PORTVERSION=${PORTVERSION} \
		VERSIONSUFFIX=${VERSIONSUFFIX}

.if ${FLAVOR} == nox11
MAKE_ARGS+=	UISTYLE=text
PKGMESSAGE=	${PKGDIR}/pkg-message.nox11
PLIST_SUB+=	X11="@comment "
.else
MAKE_ARGS+=	UISTYLE=gtk2
SUB_FILES=	${PORTNAME}.desktop
USE_GNOME+=	atk cairo gdkpixbuf glib20 gtk20 pango
USES+=		gettext-runtime gnome
PLIST_SUB+=	X11=""
.endif

OPTIONS_DEFINE=		DOCS

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USE_BINUTILS=	yes
.endif

pre-patch:
# BCP 5/16: Eta-expand for backward compatibility with OCaml >4.02
	@${REINPLACE_CMD} -e 's,= Unix\.symlink,s1 s2 & s1 s2,' \
		${WRKSRC}/system/system_generic.ml

post-build:
	(cd ${WRKSRC} && HOME=${WRKSRC} ./unison -selftest -ui text -batch)
.if ${FLAVOR} == x11
	@${ECHO} Building text-only version
	@${ECHO} ${WRKSRC}
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} -C ${WRKSRC} CFLAGS="" UISTYLE=text NAME=unison-text
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

.include <bsd.port.mk>
