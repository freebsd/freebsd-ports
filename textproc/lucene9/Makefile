PORTNAME=	lucene
PORTVERSION=	9.12.2	# Java 21+ required for Lucene 10.*
CATEGORIES=	textproc java devel
MASTER_SITES=	https://archive.apache.org/dist/${PORTNAME}/java/${PORTVERSION}/
PKGNAMESUFFIX=	9

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Full-text search engine for Java, 9.x branch
WWW=		https://lucene.apache.org/core/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cpe java:run tar:tgz
JAVA_VERSION=	11+

CONFLICTS=	lucene-[0-9].*

NO_BUILD=	yes
NO_ARCH=	yes

CPE_VENDOR=	apache

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	CONTRIB DOCS
OPTIONS_DEFAULT=CONTRIB
OPTIONS_SUB=	yes
CONTRIB_DESC=	Install contributed jars

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/modules/${PORTNAME}-core-${PORTVERSION}.jar \
		${STAGEDIR}${JAVAJARDIR}

do-install-CONTRIB-on:
	${FIND} ${WRKSRC}/modules -name "*.jar" -a ! -name "lucene-core*" -exec \
		${INSTALL_DATA} {} ${STAGEDIR}${JAVAJARDIR} \;
	${FIND} ${WRKSRC}/modules-thirdparty -name "*.jar" -exec \
		${INSTALL_DATA} {} ${STAGEDIR}${JAVAJARDIR} \;
	@${MKDIR} ${STAGEDIR}${DATADIR}/licenses
	${FIND} ${WRKSRC}/licenses -name "*.txt" -exec \
		${INSTALL_DATA} {} ${STAGEDIR}${DATADIR}/licenses \;

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in CHANGES.txt JRE_VERSION_MIGRATION.md MIGRATE.md NOTICE.txt README.md \
	SYSTEM_REQUIREMENTS.md
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR})
	${RM} -r ${STAGEDIR}${DOCSDIR}/misc/org/apache/lucene/misc/search/similarity \
		${STAGEDIR}${DOCSDIR}/test-framework/org/apache/lucene/tests/util/hnsw

.include <bsd.port.mk>
