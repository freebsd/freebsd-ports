# Created by: Niels Heinen
# $FreeBSD$

PORTNAME=	fuzzdb
PORTVERSION=	1.09
CATEGORIES=	security www
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Comprehensive set of fuzzing patterns

NO_BUILD=	yes
EXTRACT_AFTER_ARGS=	--exclude .svn
PORTDOCS=	_copyright.txt _readme.txt
PORTDIRS=	attack-payloads wordlists-misc Discovery \
		web-backdoors wordlists-user-passwd regex

NO_STAGE=	yes

OPTIONS_DEFINE=	DOCS 

.include <bsd.port.options.mk>

do-install:
.for dir in ${PORTDIRS}
	( cd ${WRKSRC}/${dir} && ${COPYTREE_SHARE} . ${DATADIR}/${dir} )
.endfor
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.	for doc in ${PORTDOCS}
		${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.	endfor
.endif

.include <bsd.port.mk>
