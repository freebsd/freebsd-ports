# New ports collection makefile for:	aolserver-nscache
# Date created:		12 Oct 2006
# Whom:			Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aolserver-nscache
PORTVERSION=	1.5
CATEGORIES=	www databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	aolserver
DISTFILES=	nscache-${PORTVERSION}.tar.gz
DIST_SUBDIR=	aolserver

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Tcl interface to AOLserver's caching API

WRKSRC=		${WRKDIR}/nscache-${PORTVERSION}

AOLSERVERBASE?=	${PREFIX}/aolserver
BUILD_DEPENDS+=	${AOLSERVERBASE}/bin/nsd:${PORTSDIR}/www/aolserver
RUN_DEPENDS+=	${BUILD_DEPENDS}
PLIST_SUB+=	AOLSERVERBASE=${AOLSERVERBASE:S/${PREFIX}\///}

USE_GMAKE=	yes

MAKE_ARGS=	AOLSERVER=${AOLSERVERBASE}

.if !defined(NOPORTDOCS)
PORTDOCS=	ChangeLog index.html
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

.include <bsd.port.mk>
