# New ports collection makefile for:	XT
# Date created:		23 June 1999
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xt
PORTVERSION=	20020426a
CATEGORIES=	textproc java
MASTER_SITES=	http://www.blnz.com/xt/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XSL Transformations (XSLT) implementation in Java

RUN_DEPENDS=	${JAVALIBDIR}/xml-apis.jar:${PORTSDIR}/textproc/xml4j \
		${JAVALIBDIR}/xp.jar:${PORTSDIR}/textproc/xp \
		${LOCALBASE}/bin/classpath:${PORTSDIR}/java/javavmwrapper

USE_JAVA=	YES
JAVA_VERSION=	1.1+
NO_BUILD=	YES
ONLY_FOR_ARCHS=	i386

.if !defined(NOPORTDOCS)
OTHERDOCS=	copying.txt copyingjc.txt index.html
PORTDOCS=	${OTHERDOCS} api
.endif
SAMPLES=	date.xsl nxml.xsl slides.xml slides.xsl sort-uniq.xml \
		sort-uniq.xsl split.xml split.xsl textfile.xml textfile.xsl

do-configure:
	${SED} -e 's,%%LOCALBASE%%,${LOCALBASE},g' ${FILESDIR}/xt.sh > ${WRKSRC}/xt

do-install:
	@${ECHO_MSG} ">> Installing JAR as ${JAVAJARDIR}/${JARFILE}..."
	${MKDIR} ${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/xt.jar ${JAVAJARDIR}/
	@${ECHO_MSG} "  [ DONE ]"
	@${ECHO_MSG} ">> Installing scripts in ${PREFIX}/bin/..."
	${INSTALL_SCRIPT} ${WRKSRC}/xt ${PREFIX}/bin/
	cd ${PREFIX}/bin && ${LN} xt xt-xp
	cd ${PREFIX}/bin && ${LN} xt xt-xml4j
	@${ECHO_MSG} "  [ DONE ]"
	@${ECHO_MSG} ">> Installing samples in ${EXAMPLESDIR}..."
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/demo && ${INSTALL_DATA} ${SAMPLES} ${EXAMPLESDIR}/
	@${ECHO_MSG} "  [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} ">> Installing documentation in ${DOCSDIR}..."
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${FIND} api \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} > /dev/null 2>&1
	cd ${WRKSRC} && ${INSTALL_DATA} ${OTHERDOCS} ${DOCSDIR}/
	@${ECHO_MSG} "  [ DONE ]"
.endif

.include <bsd.port.mk>
