# New ports collection makefile for: unison
# Date created:		4 October 2000
# Whom:			Dan Pelleg <dpelleg+unison@cs.cmu.edu>
#
# $FreeBSD$
#

PORTNAME=	unison
PORTVERSION=	2.27.29
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://www.cis.upenn.edu/~bcpierce/unison/download/releases/${DISTNAME}/
PKGNAMESUFFIX=	-devel
DISTFILES=	${EXTRACT_ONLY} ${EXTRA_DOCS}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}.tar.gz

MAINTAINER=	daniel+unison@pelleg.org
COMMENT=	A user-level file synchronization tool

PLIST_SUB=	PORTVERSION=${PORTVERSION}
USE_GMAKE=	yes
MAKE_ARGS=	CFLAGS=""
CONFLICTS=	unison-[0-9]* unison-nox11-[0-9]*

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
DOCS=		BUGS.txt NEWS README
EXTRA_DOCS=	unison-${PORTVERSION}-manual.html \
		unison-${PORTVERSION}-manual.pdf unison-${PORTVERSION}-manual.ps
.endif

.if !defined(WITHOUT_GTK2) && !defined(WITHOUT_X11)
WITH_GTK2=	yes
.endif

.if defined(WITH_GTK2)
MAKE_ARGS+=	UISTYLE=gtk2
PLIST_SUB+=	TEXT=""
BUILD_DEPENDS+=	ocamlc:${PORTSDIR}/lang/ocaml \
		lablgtk2:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2
RUN_DEPENDS+=	lablgtk2:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2
PATCH_DEPENDS+=	${BUILD_DEPENDS}
CONFLICTS+=	ocaml-nox11*
.else
MAKE_ARGS+=	UISTYLE=text
PLIST_SUB+=	TEXT="@comment "
BUILD_DEPENDS+=	ocamlc:${PORTSDIR}/lang/ocaml-nox11
PATCH_DEPENDS+=	${BUILD_DEPENDS}
.endif

.if defined(WITH_GTK2)
post-build:
	@${ECHO} Building text-only version
	@${ECHO} ${WRKSRC}
	@${GMAKE} -C ${WRKSRC} UISTYLE=text NAME=unison-text
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unison ${PREFIX}/bin

post-install:
.if defined(WITH_GTK2)
	@${INSTALL_PROGRAM} ${WRKSRC}/unison-text ${PREFIX}/bin
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${EXTRA_DOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
