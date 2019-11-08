# Created by: Dan Pelleg <dpelleg+unison@cs.cmu.edu>
# $FreeBSD$

PORTNAME=	unison
PORTVERSION=	2.32.52
PORTREVISION=	10
CATEGORIES=	net
MASTER_SITES=	http://www.cis.upenn.edu/~bcpierce/unison/download/releases/${DISTNAME}/
DISTFILES=	${EXTRACT_ONLY} ${EXTRA_DOCS}
DIST_SUBDIR=	${DISTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	mandree@FreeBSD.org
# Implicit approval for port changes granted to Guido Falsi <madpilot@FreeBSD.org>
COMMENT=	User-level file synchronization tool

LICENSE=	GPLv3

FLAVORS=	x11 nox11
FLAVOR?=	${FLAVORS[1]}

VERSIONSUFFIX=	232

nox11_PKGNAMESUFFIX=		${VERSIONSUFFIX}-nox11
nox11_CONFLICTS_INSTALL=	unison${VERSIONSUFFIX}

x11_PKGNAMESUFFIX=		${VERSIONSUFFIX}
x11_CONFLICTS_INSTALL=		unison${VERSIONSUFFIX}-nox11
x11_BUILD_DEPENDS=	lablgtk2:x11-toolkits/ocaml-lablgtk2 \
			icotool:graphics/icoutils
x11_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2
x11_RUN_DEPENDS=	lablgtk2:x11-toolkits/ocaml-lablgtk2

PLIST_SUB=	PORTVERSION=${PORTVERSION}
USES=		gmake
USE_OCAML=	yes
NO_OCAML_RUNDEPENDS=yes
MAKE_ARGS=	CFLAGS=""
MAKE_JOBS_UNSAFE=	yes

DOCS=		BUGS.txt NEWS README
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
EXTRA_DOCS=	${DISTNAME}-manual.html \
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

.if ${FLAVOR} == x11
post-patch:
	@${REINPLACE_CMD} -Ee 's@(\+|/)(lablgtk2)@\1site-lib/\2@' \
		${WRKSRC}/Makefile.OCaml

post-build:
	@${ECHO} Building text-only version
	@${ECHO} ${WRKSRC}
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} -C ${WRKSRC} CFLAGS="" UISTYLE=text NAME=${PORTNAME}-text
	@cd ${WRKSRC}/win32rc && ${LOCALBASE}/bin/icotool -x U.ico
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}${VERSIONSUFFIX}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${EXTRA_DOCS} ${STAGEDIR}${DOCSDIR}
.if ${FLAVOR} == x11
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}-text ${STAGEDIR}${PREFIX}/bin/${PORTNAME}${VERSIONSUFFIX}-text
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}/${PORTNAME}${VERSIONSUFFIX}.desktop
	${INSTALL_DATA} ${WRKSRC}/win32rc/U_4_48x48x32.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}${VERSIONSUFFIX}.png
.endif

.include <bsd.port.mk>
