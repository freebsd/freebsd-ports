# Created by: Dan Pelleg <dpelleg+unison@cs.cmu.edu>
# $FreeBSD$

PORTNAME=	unison
PORTVERSION=	2.48.1
CATEGORIES=	net
MASTER_SITES=	http://www.cis.upenn.edu/~bcpierce/unison/download/releases/${DISTNAME}/
PKGNAMESUFFIX=	-devel
DISTFILES=	${EXTRACT_ONLY} ${EXTRA_DOCS}
DIST_SUBDIR=	${DISTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	User-level file synchronization tool

IGNORE=		No devel release available. \
		Install net/unison which is the latest stable version.

LICENSE=	GPLv3

PLIST_SUB=	PORTVERSION=${PORTVERSION}
USES=		gmake
USE_OCAML=	yes
NO_OCAML_RUNDEPENDS=yes
WANT_GNOME=	yes
MAKE_ARGS=	CFLAGS=""
CONFLICTS=	unison-[0-9]* unison-nox11-[0-9]*

DOCS=		BUGS.txt NEWS README
EXTRA_DOCS=	${DISTNAME}-manual.html \
		${DISTNAME}-manual.pdf ${DISTNAME}-manual.ps

OPTIONS_DEFINE=	DOCS X11
OPTIONS_DEFAULT=	X11

MAKE_JOBS_UNSAFE=	yes
ALL_TARGET=	unison all

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
MAKE_ARGS+=	UISTYLE=gtk2
PLIST_SUB+=	TEXT=""
BUILD_DEPENDS+= lablgtk2:x11-toolkits/ocaml-lablgtk2 \
		icotool:graphics/icoutils
RUN_DEPENDS+=	lablgtk2:x11-toolkits/ocaml-lablgtk2
SUB_FILES+=	${PORTNAME}.desktop
.else
MAKE_ARGS+=	UISTYLE=text
PLIST_SUB+=	TEXT="@comment "
PKGMESSAGE=	${PKGDIR}/pkg-message.nox11
.endif

.if ${PORT_OPTIONS:MX11}
post-patch:
	@${REINPLACE_CMD} -Ee 's@(\+|/)(lablgtk2)@\1site-lib/\2@' \
		${WRKSRC}/Makefile.OCaml

post-build:
	@${ECHO} Building text-only version
	@${ECHO} ${WRKSRC}
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} -C ${WRKSRC} CFLAGS="" UISTYLE=text NAME=unison-text
	@cd ${WRKSRC}/win32rc && ${LOCALBASE}/bin/icotool -x U.ico
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unison ${STAGEDIR}${PREFIX}/bin

post-install:
.if ${PORT_OPTIONS:MX11}
	${INSTALL_PROGRAM} ${WRKSRC}/unison-text ${STAGEDIR}${PREFIX}/bin
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${EXTRA_DOCS} ${STAGEDIR}${DOCSDIR}
.if ${PORT_OPTIONS:MX11}
	${INSTALL_PROGRAM} ${WRKSRC}/unison-text ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/win32rc/U_4_48x48x32.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
.endif

.include <bsd.port.mk>
