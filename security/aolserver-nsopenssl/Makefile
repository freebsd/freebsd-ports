# New ports collection makefile for:	aolserver-nsopenssl
# Date created:		12 Oct 2006
# Whom:			Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aolserver-nsopenssl
PORTVERSION=	3.0.b26
PORTREVISION=	1
CATEGORIES=	security www
MASTER_SITES=	SF/aolserver/nsopenssl/3.0
DISTFILES=	nsopenssl-3.0beta26-src.tar.gz
DIST_SUBDIR=	aolserver

MAINTAINER=	mm@FreeBSD.org
COMMENT=	OpenSSL socket encryption module for AOLserver

WRKSRC=		${WRKDIR}/nsopenssl-3.0beta26

AOLSERVERBASE?=	aolserver
BUILD_DEPENDS+=	${LOCALBASE}/${AOLSERVERBASE}/bin/nsd:${PORTSDIR}/www/aolserver
RUN_DEPENDS+=	${LOCALBASE}/${AOLSERVERBASE}/bin/nsd:${PORTSDIR}/www/aolserver
PLIST_SUB+=	AOLSERVERBASE=${AOLSERVERBASE}

USE_OPENSSL=	yes
USE_GMAKE=	yes

MAKE_ARGS=	AOLSERVER=${LOCALBASE}/${AOLSERVERBASE} OPENSSL=${OPENSSLBASE}

.if !defined(NOPORTDOCS)
PORTDOCS=	ChangeLog README TODO
.endif

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	@ ${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
