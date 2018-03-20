# Created by: Miroslav Lachman <000.fbsd@quip.cz>
# $FreeBSD$

PORTNAME=	search-guard
DISTVERSION=	5.6.8
DISTVERSIONSUFFIX=-19
CATEGORIES=	textproc java
MASTER_SITES=	https://oss.sonatype.org/content/repositories/releases/com/floragunn/search-guard-5/${DISTVERSIONFULL}/
PKGNAMEPREFIX=	elasticsearch5-
DISTNAME=	search-guard-5-${DISTVERSIONFULL}

MAINTAINER=	elastic@FreeBSD.org
COMMENT=	Elasticsearch Search Guard plugin

LICENSE=	APACHE20

RUN_DEPENDS:=	elasticsearch5>=${DISTVERSION}:textproc/elasticsearch5

NO_ARCH=	yes
NO_BUILD=	yes

USES+=		zip shebangfix

SCRIPTS=	hash.sh install_demo_configuration.sh sgadmin.sh
SHEBANG_FILES=	./elasticsearch/tools/*.sh

do-extract:
	${MKDIR} ${WRKSRC}
	( cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} -d ${DISTNAME} \
	      ${_DISTDIR}${DISTFILES} )

post-patch:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' -e 's|%%BASH%%|${bash_CMD}|' \
		${SCRIPTS:S|^|${WRKSRC}/elasticsearch/tools/|}
	${FIND} ${WRKSRC} '(' -name '*.bat' -o -name '*.bak' -o -name '*.orig' ')' -delete

do-install:
	cd ${WRKSRC}/elasticsearch && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins/search-guard-5
	${CHMOD} 555 ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins/search-guard-5/tools/*.sh
	${CHMOD} 644 ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins/search-guard-5/sgconfig/*

post-install:
	${FIND} -s ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins/ -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}

.include <bsd.port.mk>
