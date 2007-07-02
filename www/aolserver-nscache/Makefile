# New ports collection makefile for:	aolserver-nscache
# Date created:		12 Oct 2006
# Whom:			Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aolserver-nscache
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	www databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	aolserver
DISTFILES=	nscache-${PORTVERSION}.tar.gz
DIST_SUBDIR=	aolserver

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Tcl interface to AOLserver's caching API

WRKSRC=		${WRKDIR}/nscache-${PORTVERSION}

AOLSERVERBASE?=	aolserver
BUILD_DEPENDS+=	${LOCALBASE}/${AOLSERVERBASE}/bin/nsd:${PORTSDIR}/www/aolserver
RUN_DEPENDS+=	${BUILD_DEPENDS}

USE_GMAKE=	yes

MAKE_ARGS=	AOLSERVER="${LOCALBASE}/${AOLSERVERBASE}"

PLIST_FILES=	${AOLSERVERBASE}/bin/nscache.so \
		${AOLSERVERBASE}/lib/libnscache.a \
		${AOLSERVERBASE}/lib/libnscache.so

.if !defined(NOPORTDOCS)
PORTDOCS=	ChangeLog index.html
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e '/^OBJS     =.*/{p;s/OBJS     =.*/MODOBJS  = $$(OBJS)/g;}' \
		${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	@ ${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
