# New ports collection makefile for: unison
# Date created:		4 October 2000
# Whom:			Dan Pelleg <dpelleg+unison@cs.cmu.edu>
#
# $FreeBSD$
#

PORTNAME=	unison
PORTVERSION=	2.10.2
CATEGORIES=	net
MASTER_SITES=	http://www.cis.upenn.edu/~bcpierce/unison/download/beta-test/${DIST_SUBDIR}/
DISTFILES=	${EXTRACT_ONLY} ${EXTRA_DOCS}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}.tar.gz

MAINTAINER=	daniel+unison@pelleg.org
COMMENT=	A user-level file synchronization tool

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml-nox11
PATCH_DEPENDS=	${BUILD_DEPENDS}

PLIST_SUB=	PORTVERSION=${PORTVERSION}
USE_GMAKE=	yes
MAKE_ARGS=	CFLAGS=""

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
DOCS=		BUGS.txt NEWS README
EXTRA_DOCS=	unison-${PORTVERSION}-manual.html \
		unison-${PORTVERSION}-manual.pdf unison-${PORTVERSION}-manual.ps
.endif

.if !defined(WITHOUT_GTK2) && !defined(WITHOUT_X11) && exists(${LOCALBASE}/bin/lablgtk2)
WITH_GTK2=	yes
.endif

.if defined(WITH_GTK2)
MAKE_ARGS+=	UISTYLE=gtk2
RUN_DEPENDS+=	lablgtk2:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2
BUILD_DEPENDS+=	lablgtk2:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2
PLIST_SUB+=	TEXT=""
.else
MAKE_ARGS+=	UISTYLE=text
PLIST_SUB+=	TEXT="@comment "
.endif

.if defined(WITH_GTK2)
post-build:
	@${ECHO} Building text-only version
	@${ECHO} ${WRKSRC}
	@${GMAKE} -C ${WRKSRC} UISTYLE=text NAME=unison-text
.endif

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/unison
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
