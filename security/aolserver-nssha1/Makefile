# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aolserver-nssha1
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	security www
MASTER_SITES=	SF/aolserver/nssha1/nssha1-${PORTVERSION}
DISTFILES=	nssha1-${PORTVERSION}.tar.gz
DIST_SUBDIR=	aolserver

MAINTAINER=	ports@FreeBSD.org
COMMENT=	AOLserver module to perform SHA1 hashes

WRKSRC=		${WRKDIR}/nssha1-${PORTVERSION}

LICENSE=	GPLv1 MPL
LICENSE_COMB=	dual

AOLSERVERBASE?=	aolserver
BUILD_DEPENDS+=	${LOCALBASE}/${AOLSERVERBASE}/bin/nsd:${PORTSDIR}/www/aolserver
RUN_DEPENDS+=	${LOCALBASE}/${AOLSERVERBASE}/bin/nsd:${PORTSDIR}/www/aolserver
PLIST_SUB+=	AOLSERVERBASE=${AOLSERVERBASE}

USE_GMAKE=	yes

MAKE_ARGS=	AOLSERVER=${LOCALBASE}/${AOLSERVERBASE} OPENSSL=${OPENSSLBASE}

.if !defined(NOPORTDOCS)
PORTDOCS=	ChangeLog
.endif

NO_STAGE=	yes
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
