PORTNAME=	xmlbeans
DISTVERSION=	5.3.0 # Do not upgrade without checking compatibility with math/R-cran-XLConnect
PORTREVISION=	1
CATEGORIES=	textproc java
MASTER_SITES=	https://archive.apache.org/dist/poi/xmlbeans/release/bin/
PKGNAMEPREFIX=	apache-
DISTNAME=	apache-${PORTNAME}-bin-${PORTVERSION}-${DATE_REL}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Java classes for XML
WWW=		https://xmlbeans.apache.org/

LICENSE=	APACHE20

RUN_DEPENDS=	apache-log4j2>0:devel/apache-log4j2	\
		slf4j>0:devel/slf4j

USES=		cpe java tar:tgz
DATE_REL=	20241203
CPE_VENDOR=	apache

JAVA_VERSION=	11+

WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}
NO_BUILD=	yes
NO_ARCH=	yes
SUB_FILES=	pkg-message

OTHERDOCS=	LICENSE.txt NOTICE.txt README.txt
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=		DOCS EXAMPLES SAXON
OPTIONS_DEFAULT=	SAXON
SAXON_DESC=		Saxon XQuery processor for full XQuery and XPath support
SAXON_RUN_DEPENDS=	saxon-he>=12:textproc/saxon-he

pre-configure:
	${REINPLACE_CMD} -e 's|%%JAVAJARDIR%%|${JAVAJARDIR}|'	\
		${WRKSRC}/bin/_setlib
	${SED} -i '' -e 's|xbean.jar|xmlbeans.jar|;s|:$$XMLBEANS_LIB/xmlbeans-qname.jar||;s|:$XMLBEANS_LIB/jsr173_1.0_api.jar||;s|:$XMLBEANS_LIB/resolver.jar||'	\
		${WRKSRC}/bin/*

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}	\
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME}-${PORTVERSION}.jar	\
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
	${FIND} ${WRKSRC}/bin ! -name "*.cmd" -type f -exec	\
		${INSTALL_SCRIPT} {} ${STAGEDIR}${PREFIX}/bin \;

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${OTHERDOCS} ${STAGEDIR}${DOCSDIR})

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/samples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
