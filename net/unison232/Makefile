# New ports collection makefile for: unison
# Date created:		4 October 2000
# Whom:			Dan Pelleg <dpelleg+unison@cs.cmu.edu>
#
# $FreeBSD$
#

PORTNAME=	unison
PORTVERSION=	2.32.52
CATEGORIES=	net
MASTER_SITES=	http://www.cis.upenn.edu/~bcpierce/unison/download/releases/${DISTNAME}/
PKGNAMESUFFIX=	232
DISTFILES=	${EXTRACT_ONLY} ${EXTRA_DOCS}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}.tar.gz

MAINTAINER=	mandree@FreeBSD.org
# Implicit approval for port changes granted to Guido Falsi <mad@madpilot.net>
COMMENT=	A user-level file synchronization tool

PLIST_SUB=	PORTVERSION=${PORTVERSION}
USE_GMAKE=	yes
WANT_GNOME=	yes
MAKE_ARGS=	CFLAGS=""

MAKE_JOBS_UNSAFE=	yes

LICENCE=	GPLv3

.if defined(WITHOUT_X11)
WITHOUT_GTK2=	yes
.else
OPTIONS=	GTK2 "Build a GTK2-based version" on
.endif

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
DOCS=		BUGS.txt NEWS README
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
EXTRA_DOCS=	${PORTNAME}-${PORTVERSION}-manual.html \
		${PORTNAME}-${PORTVERSION}-manual.pdf ${PORTNAME}-${PORTVERSION}-manual.ps
.endif

.if !defined(WITHOUT_GTK2)
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

.if !defined(WITHOUT_GTK2)
post-build:
	@${ECHO} Building text-only version
	@${ECHO} ${WRKSRC}
	${GMAKE} -C ${WRKSRC} UISTYLE=text NAME=${PORTNAME}-text
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}${PKGNAMESUFFIX}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${EXTRA_DOCS} ${DOCSDIR}
.endif
.if !defined(WITHOUT_GTK2)
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}-text ${PREFIX}/bin/${PORTNAME}${PKGNAMESUFFIX}-text
	${MKDIR} ${DESKTOPDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.desktop ${DESKTOPDIR}/${PORTNAME}${PKGNAMESUFFIX}.desktop
	-update-desktop-database > /dev/null
.endif

.include <bsd.port.post.mk>
