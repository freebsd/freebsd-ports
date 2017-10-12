# Created by: Dan Pelleg <dpelleg+unison@cs.cmu.edu>
# $FreeBSD$

PORTNAME=	unison
PORTVERSION=	2.32.52
PORTREVISION=	9
CATEGORIES=	net
MASTER_SITES=	http://www.cis.upenn.edu/~bcpierce/unison/download/releases/${DISTNAME}/
PKGNAMESUFFIX=	232
DISTFILES=	${EXTRACT_ONLY} ${EXTRA_DOCS}
DIST_SUBDIR=	${DISTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	mandree@FreeBSD.org
# Implicit approval for port changes granted to Guido Falsi <madpilot@FreeBSD.org>
COMMENT=	User-level file synchronization tool

LICENSE=	GPLv3

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

OPTIONS_DEFINE=		DOCS X11
OPTIONS_DEFAULT=	X11

X11_MAKE_ARGS=		UISTYLE=gtk2
X11_PLIST_SUB=		TEXT=""
X11_BUILD_DEPENDS=	lablgtk2:x11-toolkits/ocaml-lablgtk2 \
			icotool:graphics/icoutils
X11_RUN_DEPENDS=	lablgtk2:x11-toolkits/ocaml-lablgtk2
X11_SUB_FILES=		${PORTNAME}.desktop

X11_MAKE_ARGS_OFF=	UISTYLE=text
X11_PLIST_SUB_OFF=	TEXT="@comment "

post-patch-X11-on:
	@${REINPLACE_CMD} -Ee 's@(\+|/)(lablgtk2)@\1site-lib/\2@' \
		${WRKSRC}/Makefile.OCaml

post-build-X11-on:
	@${ECHO} Building text-only version
	@${ECHO} ${WRKSRC}
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} -C ${WRKSRC} CFLAGS="" UISTYLE=text NAME=${PORTNAME}-text
	@cd ${WRKSRC}/win32rc && ${LOCALBASE}/bin/icotool -x U.ico

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}${PKGNAMESUFFIX}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${EXTRA_DOCS} ${STAGEDIR}${DOCSDIR}

do-install-X11-on:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}-text ${STAGEDIR}${PREFIX}/bin/${PORTNAME}${PKGNAMESUFFIX}-text
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}/${PORTNAME}${PKGNAMESUFFIX}.desktop
	${INSTALL_DATA} ${WRKSRC}/win32rc/U_4_48x48x32.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}${PKGNAMESUFFIX}.png

.include <bsd.port.mk>
