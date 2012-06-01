# New ports collection makefile for: unison
# Date created:		4 October 2000
# Whom:			Dan Pelleg <dpelleg+unison@cs.cmu.edu>
#
# $FreeBSD$
#

PORTNAME=	unison
PORTVERSION=	2.45.4
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.cis.upenn.edu/~bcpierce/unison/download/releases/${DISTNAME}/
PKGNAMESUFFIX=	-devel
DISTFILES=	${EXTRACT_ONLY} ${EXTRA_DOCS}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}.tar.gz

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	A user-level file synchronization tool

LICENSE=	GPLv3

PLIST_SUB=	PORTVERSION=${PORTVERSION}
USE_GMAKE=	yes
WANT_GNOME=	yes
MAKE_ARGS=	CFLAGS=""
CONFLICTS=	unison-[0-9]* unison-nox11-[0-9]*

OPTIONS_DEFINE=	DOCS GTK2
OPTIONS_DEFAULT=	DOCS GTK2

MAKE_JOBS_UNSAFE=	yes
ALL_TARGET=	unison all

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DOCS=		BUGS.txt NEWS README
EXTRA_DOCS=	unison-${PORTVERSION}-manual.html \
		unison-${PORTVERSION}-manual.pdf unison-${PORTVERSION}-manual.ps
.endif

.if ${PORT_OPTIONS:MGTK2}
MAKE_ARGS+=	UISTYLE=gtk2
PLIST_SUB+=	TEXT=""
BUILD_DEPENDS+=	ocamlc:${PORTSDIR}/lang/ocaml \
		lablgtk2:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2
RUN_DEPENDS+=	lablgtk2:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2
PATCH_DEPENDS+=	${BUILD_DEPENDS}
CONFLICTS+=	ocaml-nox11*
USE_GNOME=	desktopfileutils
SUB_FILES+=	${PORTNAME}.desktop
.else
MAKE_ARGS+=	UISTYLE=text
PLIST_SUB+=	TEXT="@comment "
BUILD_DEPENDS+=	ocamlc:${PORTSDIR}/lang/ocaml-nox11
PATCH_DEPENDS+=	${BUILD_DEPENDS}
.endif

.if ${PORT_OPTIONS:MGTK2}
post-build:
	@${ECHO} Building text-only version
	@${ECHO} ${WRKSRC}
	@${GMAKE} -C ${WRKSRC} UISTYLE=text NAME=unison-text
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unison ${PREFIX}/bin

post-install:
.if ${PORT_OPTIONS:MGTK2}
	@${INSTALL_PROGRAM} ${WRKSRC}/unison-text ${PREFIX}/bin
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${EXTRA_DOCS} ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MGTK2}
	@${INSTALL_PROGRAM} ${WRKSRC}/unison-text ${PREFIX}/bin
	@${MKDIR} ${DESKTOPDIR}
	@${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.desktop ${DESKTOPDIR}
	@-update-desktop-database > /dev/null
	@${CAT} ${PKGMESSAGE}
.else
	@${CAT} ${PKGMESSAGE}.nox11
.endif

.include <bsd.port.mk>
