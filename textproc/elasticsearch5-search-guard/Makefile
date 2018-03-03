# Created by: Miroslav Lachman <000.fbsd@quip.cz>
# $FreeBSD$

PORTNAME=	search-guard
DISTVERSION=	5.3.0-12
CATEGORIES=	textproc java
MASTER_SITES=	https://oss.sonatype.org/content/repositories/releases/com/floragunn/search-guard-5/${DISTVERSION}/
PKGNAMEPREFIX=	elasticsearch5-
DISTNAME=	search-guard-5-${DISTVERSION}

MAINTAINER=	elastic@FreeBSD.org
COMMENT=	Elasticsearch Search Guard plugin

LICENSE=	APACHE20

RUN_DEPENDS:=	elasticsearch5>=5.3.0:textproc/elasticsearch5

NO_BUILD=	yes

USES+=		zip shebangfix

SCRIPTS=	hash.sh install_demo_configuration.sh sgadmin.sh
SHEBANG_FILES=	./elasticsearch/tools/*.sh

do-extract:
	@${MKDIR} ${WRKSRC}
	( cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} -d ${DISTNAME} \
	      ${_DISTDIR}${DISTFILES} )

pre-configure:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${SCRIPTS:S|^|${WRKSRC}/elasticsearch/tools/|}

post-configure:
	@${RM} ${WRKSRC}/elasticsearch/tools/*.bat
	@${RM} ${WRKSRC}/elasticsearch/tools/install_demo_configuration.sh.orig

do-install:
	@cd ${WRKSRC}/elasticsearch && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins/search-guard-5 "! -name *\.bak -o ! -name *\.bat"
	@${CHMOD} 544 ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins/search-guard-5/tools/*.sh
	@${CHMOD} 644 ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins/search-guard-5/sgconfig/*

.include <bsd.port.mk>
