# New ports collection makefile for:    fuzzdb
# Date created:				2010-04-14
# Whom:					Niels Heinen
#
# $FreeBSD$
#

PORTNAME=	fuzzdb
PORTVERSION=	1.06
CATEGORIES=	security www
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	niels@FreeBSD.org
COMMENT=	A comprehensive set of fuzzing patterns

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
EXTRACT_AFTER_ARGS=	| ${TAR} -xf - --exclude .svn
PORTDOCS=	_copyright.txt _readme.txt
PORTDIRS=	attack-payloads wordlists-misc discovery \
		web-backdoors wordlists-user-passwd

.include <bsd.port.pre.mk>

do-install:
.for dir in ${PORTDIRS}
	( cd ${WRKSRC}/${dir} && ${COPYTREE_SHARE} . ${DATADIR}/${dir} )
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.	for doc in ${PORTDOCS}
		${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.	endfor
.endif

.include <bsd.port.post.mk>
