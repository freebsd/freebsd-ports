# New ports collection makefile for:	aolserver-nsmhash
# Date created:		12 Oct 2006
# Whom:			Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nsmhash
PORTVERSION=	1.1
CATEGORIES=	security www
MASTER_SITES=	http://www.aolserver.cz/download/
PKGNAMEPREFIX=	aolserver-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	aolserver

MAINTAINER=	mm@FreeBSD.org
COMMENT=	AOLserver interface to mhash library

WRKSRC=		${WRKDIR}

AOLSERVERBASE?=	aolserver
LIB_DEPENDS+=	mhash.2:${PORTSDIR}/security/mhash
BUILD_DEPENDS+=	${LOCALBASE}/${AOLSERVERBASE}/bin/nsd:${PORTSDIR}/www/aolserver
RUN_DEPENDS+=	${BUILD_DEPENDS}

USE_GMAKE=	yes
MAKEFILE=	Makefile.ns

USE_TCL=	84+
USE_TCL_THREADS=	yes

PLIST_FILES=	${AOLSERVERBASE}/bin/nsmhash.so \
		${AOLSERVERBASE}/lib/libnsmhash.a \
		${AOLSERVERBASE}/lib/libnsmhash.so

.include <bsd.port.pre.mk>

CFLAGS+=	"-I${LOCALBASE}/include"
MAKE_ARGS+=	NSHOME="${LOCALBASE}/${AOLSERVERBASE}" \
		DLLLIBS="-L${LOCALBASE}/lib -lmhash" \
		MODLIBS="-L${LOCALBASE}/lib -lmhash"

.if !defined(NOPORTDOCS)
PORTDOCS=	AUTHORS CHANGES COPYING README
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/^CFLAGS   =/CFLAGS  +=/g' \
		-e 's/^MODLIBS  =/MODLIBS +=/g' \
		-e '/^OBJS     =.*/{n;s/.*/MODOBJS  = $$(OBJS)/g;G;}' \
		${WRKSRC}/${MAKEFILE}

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	@ ${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
