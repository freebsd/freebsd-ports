# New ports collection makefile for:	aolserver-nsmhash
# Date created:		12 Oct 2006
# Whom:			Martin Matuska <martin@matuska.org>
#
# $FreeBSD$
#

PORTNAME=	nsmhash
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	security www
MASTER_SITES=	http://www.aolserver.cz/download/
PKGNAMEPREFIX=	aolserver-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	aolserver

MAINTAINER=	martin@matuska.org
COMMENT=	AOLserver interface to mhash library

WRKSRC=		${WRKDIR}

AOLSERVERBASE?=	${PREFIX}/aolserver
LIB_DEPENDS+=	mhash.2:${PORTSDIR}/security/mhash
BUILD_DEPENDS+=	${AOLSERVERBASE}/bin/nsd:${PORTSDIR}/www/aolserver
RUN_DEPENDS+=	${BUILD_DEPENDS}
PLIST_SUB+=	AOLSERVERBASE=${AOLSERVERBASE:S/${PREFIX}\///}

USE_GMAKE=	yes

USE_TCL=	84+
USE_TCL_THREADS=	yes

.include <bsd.port.pre.mk>

MAKE_ARGS=	NSHOME=${AOLSERVERBASE} MODLIBS="-L${LOCALBASE}/lib -lmhash" \
		CFLAGS="-I. -I${AOLSERVERBASE}/include -I${LOCALBASE}/include -I${TCL_INCLUDEDIR} -DAOL4=1 -fPIC"

.if !defined(NOPORTDOCS)
PORTDOCS=	AUTHORS COPYING README
.endif

post-patch:
	@ ${REINPLACE_CMD} -e 's|OBJS|MODOBJS|' ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	@ ${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
