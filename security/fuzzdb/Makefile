# New ports collection makefile for:    fuzzdb
# Date created:				2010-04-14
# Whom:					Niels Heinen
#
# $FreeBSD$
#

PORTNAME=	fuzzdb
PORTVERSION=	1.01
CATEGORIES=	security www
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	niels@FreeBSD.org
COMMENT=	A comprehensive set of fuzzing patterns

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
EXTRACT_AFTER_ARGS=	| ${TAR} -xf - --exclude .svn
PORTDOCS=	copyright.txt

.include <bsd.port.pre.mk>

do-install:
	( cd ${WRKSRC} && ${COPYTREE_SHARE} . ${DATADIR} "! -name ${PORTDOCS}" )
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
