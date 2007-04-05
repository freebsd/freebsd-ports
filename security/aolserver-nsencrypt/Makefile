# New ports collection makefile for:	aolserver-nsencrypt
# Date created:		12 Oct 2006
# Whom:			Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aolserver-nsencrypt
PORTVERSION=	0.4
CATEGORIES=	security www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	aolserver
DISTFILES=	nsencrypt-${PORTVERSION}-src.tar.gz
DIST_SUBDIR=	aolserver

MAINTAINER=	mm@FreeBSD.org
COMMENT=	OpenSSL data encryption module for AOLserver

WRKSRC=		${WRKDIR}/nsencrypt-${PORTVERSION}

AOLSERVERBASE?=	${PREFIX}/aolserver
BUILD_DEPENDS+=	${AOLSERVERBASE}/bin/nsd:${PORTSDIR}/www/aolserver
RUN_DEPENDS+=	${BUILD_DEPENDS}
PLIST_SUB+=	AOLSERVERBASE=${AOLSERVERBASE:S/${PREFIX}\///}

USE_OPENSSL=	yes
USE_GMAKE=	yes

MAKE_ARGS=	AOLSERVER=${AOLSERVERBASE} OPENSSL=${OPENSSLBASE}

.if !defined(NOPORTDOCS)
PORTDOCS=	ChangeLog readme.txt
.endif

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	@ ${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
