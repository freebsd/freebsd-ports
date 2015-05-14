# Created by: Niels Heinen
# $FreeBSD$

PORTNAME=	fuzzdb
PORTVERSION=	1.09
CATEGORIES=	security www
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Comprehensive set of fuzzing patterns

USES=		tar:tgz
NO_BUILD=	yes
EXTRACT_AFTER_ARGS=	--exclude .svn
PORTDOCS=	_copyright.txt _readme.txt
PORTDIRS=	attack-payloads wordlists-misc Discovery \
		web-backdoors wordlists-user-passwd regex

OPTIONS_DEFINE=	DOCS

do-install:
.for dir in ${PORTDIRS}
	( cd ${WRKSRC}/${dir} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/${dir} )
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
