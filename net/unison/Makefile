# Created by: Dan Pelleg <dpelleg+unison@cs.cmu.edu>
# $FreeBSD$

PORTNAME=	unison
PORTVERSION=	2.48.4
PORTREVISION?=	2
CATEGORIES=	net
MASTER_SITES=	http://www.cis.upenn.edu/~bcpierce/unison/download/releases/${DISTNAME}/
DISTFILES=	${EXTRACT_ONLY} ${EXTRA_DOCS}
DIST_SUBDIR=	${DISTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER?=	madpilot@FreeBSD.org
COMMENT?=	User-level file synchronization tool

LICENSE=	GPLv3

PLIST_SUB=	PORTVERSION=${PORTVERSION}
USES=		gmake localbase
USE_OCAML=	yes
WRKSRC=		${WRKDIR}/src
NO_OCAML_RUNDEPENDS=yes
CONFLICTS?=	unison-devel-[0-9]* unison-nox11-[0-9]*
MAKE_ENV=	CLIBS="${LIBS:S/^-/-ccopt -/}" COFLAGS="${CFLAGS:C/ *(-[^ ]*) */ -ccopt \"\1 \"/gW}"
MAKE_JOBS_UNSAFE=	yes
ALL_TARGET=	unison all

DOCS=		BUGS.txt NEWS README
EXTRA_DOCS=	${DISTNAME}-manual.html \
		${DISTNAME}-manual.pdf ${DISTNAME}-manual.ps

OPTIONS_DEFINE=		DOCS FSMONITOR X11
OPTIONS_DEFAULT?=	FSMONITOR X11

FSMONITOR_DESC=		Compile and install fsmonitor plugin

OPTIONS_SUB=		YES

FSMONITOR_LIB_DEPENDS=	libinotify.so:devel/libinotify

X11_MAKE_ARGS=		UISTYLE=gtk2
X11_BUILD_DEPENDS=	lablgtk2:x11-toolkits/ocaml-lablgtk2 \
			icotool:graphics/icoutils
X11_RUN_DEPENDS=	lablgtk2:x11-toolkits/ocaml-lablgtk2
X11_SUB_FILES=		${PORTNAME}.desktop

X11_MAKE_ARGS_OFF=	UISTYLE=text
X11_VARS_OFF=		PKGMESSAGE=${PKGDIR}/pkg-message.nox11

post-patch-FSMONITOR-off:
	@${REINPLACE_CMD} -e 's/-include fsmonitor/#&/' \
		${WRKSRC}/Makefile.OCaml

post-patch-X11-off:
	@${REINPLACE_CMD} -e 's/CFLAGS/COFLAGS/g' \
		${WRKSRC}/Makefile.OCaml ${WRKSRC}/fsmonitor/linux/Makefile

post-patch-X11-on:
	@${REINPLACE_CMD} -Ee 's@(\+|/)(lablgtk2)@\1site-lib/\2@' \
			-e 's/CFLAGS/COFLAGS/g' \
		${WRKSRC}/Makefile.OCaml ${WRKSRC}/fsmonitor/linux/Makefile

post-build-X11-on:
	@${ECHO} Building text-only version
	@${ECHO} ${WRKSRC}
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} -C ${WRKSRC} UISTYLE=text NAME=unison-text
	@cd ${WRKSRC}/win32rc && ${LOCALBASE}/bin/icotool -x U.ico

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${EXTRA_DOCS} ${STAGEDIR}${DOCSDIR}

do-install-FSMONITOR-on:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}-fsmonitor ${STAGEDIR}${PREFIX}/bin

do-install-X11-on:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}-text ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/win32rc/U_4_48x48x32.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
