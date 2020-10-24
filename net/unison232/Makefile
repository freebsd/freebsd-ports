# Created by: Dan Pelleg <dpelleg+unison@cs.cmu.edu>
# $FreeBSD$

PORTNAME=	unison
PORTVERSION=	2.32.52
PORTREVISION=	11
CATEGORIES=	net
MASTER_SITES=	https://www.cis.upenn.edu/~bcpierce/unison/download/releases/${DISTNAME}/
DISTFILES=	${EXTRACT_ONLY} ${_EXTRA_DOCS}
DIST_SUBDIR=	${DISTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	mandree@FreeBSD.org
# Implicit approval for port changes granted to Guido Falsi <madpilot@FreeBSD.org>
COMMENT=	User-level file synchronization tool

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

FLAVORS=	x11 nox11
FLAVOR?=	${FLAVORS:[1]}

USES=		gmake

_VERSIONSUFFIX=	232

nox11_PKGNAMESUFFIX=		${_VERSIONSUFFIX}-nox11
nox11_CONFLICTS_INSTALL=	unison${_VERSIONSUFFIX}

x11_PKGNAMESUFFIX=		${_VERSIONSUFFIX}
x11_BUILD_DEPENDS=	lablgtk2:x11-toolkits/ocaml-lablgtk2 \
			icotool:graphics/icoutils
x11_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2
x11_RUN_DEPENDS=	lablgtk2:x11-toolkits/ocaml-lablgtk2
x11_CONFLICTS_INSTALL=		unison${_VERSIONSUFFIX}-nox11

PLIST_SUB=	PORTVERSION=${PORTVERSION}
USE_OCAML=	yes
NO_OCAML_RUNDEPENDS=yes
MAKE_ARGS=	CFLAGS=""

TEST_TARGET=	selftest

_DOCS=		BUGS.txt NEWS README
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
_EXTRA_DOCS=	${DISTNAME}-manual.html \
		${DISTNAME}-manual.pdf ${DISTNAME}-manual.ps

OPTIONS_DEFINE=		DOCS

.if ${FLAVOR} == nox11
MAKE_ARGS+=		UISTYLE=text
PKGMESSAGE=		${PKGDIR}/pkg-message.nox11
PLIST_SUB+=		X11="@comment "
.else
MAKE_ARGS+=		UISTYLE=gtk2
SUB_FILES=		${PORTNAME}.desktop
USE_GNOME+=		atk cairo gdkpixbuf2 glib20 gtk20 pango
USES+=			gettext-runtime gnome
PLIST_SUB+=		X11=""
.endif

post-patch:
	@${REINPLACE_CMD} -Ee 's@(\+|/)(lablgtk2)@\1site-lib/\2@' \
		${WRKSRC}/Makefile.OCaml

post-build:
	( cd ${WRKSRC} && ./unison -selftest -ui text -batch )
.if ${FLAVOR} == x11
	@${ECHO} Building text-only version in ${WRKSRC}
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} -C ${WRKSRC} CFLAGS="" UISTYLE=text NAME=${PORTNAME}-text
	@cd ${WRKSRC}/win32rc && ${LOCALBASE}/bin/icotool -x U.ico
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}${_VERSIONSUFFIX}
.if ${FLAVOR} == x11
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}-text ${STAGEDIR}${PREFIX}/bin/${PORTNAME}${_VERSIONSUFFIX}-text
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}/${PORTNAME}${_VERSIONSUFFIX}.desktop
	${INSTALL_DATA} ${WRKSRC}/win32rc/U_4_48x48x32.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}${_VERSIONSUFFIX}.png
.endif

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${_DOCS} ${STAGEDIR}${DOCSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${_EXTRA_DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
