# $FreeBSD$

PORTNAME=	xt
PORTVERSION=	20020426a
PORTREVISION=	2
CATEGORIES=	textproc java
MASTER_SITES=	http://www.blnz.com/xt/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XSL Transformations (XSLT) implementation in Java

BROKEN=		unfetchable

RUN_DEPENDS=	${JAVALIBDIR}/xml-apis.jar:textproc/xerces-j \
		${JAVALIBDIR}/xp.jar:textproc/xp

USE_JAVA=	YES
JAVA_VERSION=	1.6+
NO_BUILD=	YES

OPTIONS_DEFINE=	DOCS EXAMPLES

OTHERDOCS=	copying.txt copyingjc.txt index.html
PORTDOCS=	${OTHERDOCS} api
SAMPLES=	date.xsl nxml.xsl slides.xml slides.xsl sort-uniq.xml \
		sort-uniq.xsl split.xml split.xsl textfile.xml textfile.xsl

do-configure:
	${SED} -e 's,%%LOCALBASE%%,${LOCALBASE},g' ${FILESDIR}/xt.sh > ${WRKSRC}/xt

do-install:
	@${ECHO_MSG} ">> Installing JAR as ${JAVAJARDIR}/${JARFILE}..."
	${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/xt.jar ${STAGEDIR}${JAVAJARDIR}/
	@${ECHO_MSG} "  [ DONE ]"
	@${ECHO_MSG} ">> Installing scripts in ${PREFIX}/bin/..."
	${INSTALL_SCRIPT} ${WRKSRC}/xt ${STAGEDIR}${PREFIX}/bin/
	${LN} -sf xt ${STAGEDIR}${PREFIX}/bin/xt-xp
	${LN} -sf xt ${STAGEDIR}${PREFIX}/bin/xt-xml4j
	@${ECHO_MSG} "  [ DONE ]"
	@${ECHO_MSG} ">> Installing samples in ${EXAMPLESDIR}..."
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/demo && ${INSTALL_DATA} ${SAMPLES} ${STAGEDIR}${EXAMPLESDIR}/)
	@${ECHO_MSG} "  [ DONE ]"
	@${ECHO_MSG} ">> Installing documentation in ${DOCSDIR}..."
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${FIND} api \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR} > /dev/null 2>&1)
	(cd ${WRKSRC} && ${INSTALL_DATA} ${OTHERDOCS} ${STAGEDIR}${DOCSDIR}/)
	@${ECHO_MSG} "  [ DONE ]"

.include <bsd.port.mk>
