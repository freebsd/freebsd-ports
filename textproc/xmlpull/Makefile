# New ports collection makefile for:	xmlpull
# Date created:		2004-03-30
# Whom:			Herve Quiroz <herve.quiroz@esil.univ-mrs.fr>
#
# $FreeBSD$
#

PORTNAME=	xmlpull
PORTVERSION=	1.1.3.4a
CATEGORIES=	textproc java
MASTER_SITES=	http://www.xmlpull.org/v1/download/
DISTNAME=	${DISTNAME_PREFX}_src
EXTRACT_SUFX=	.tgz

MAINTAINER=	hq@FreeBSD.org
COMMENT=	Common API for XML Pull Parsing (XmlPull)

BUILD_DEPENDS=	${ANT}:${PORTSDIR}/devel/apache-ant

USE_JAVA=	1.3+
DISTNAME_PREFX=	${PORTNAME}_${PORTVERSION:S/./_/g}
WRKSRC=		${WRKDIR}/${DISTNAME_PREFX}

ANT?=		${LOCALBASE}/bin/ant
ANT_TARGET=	jar
.if !defined(NOPORTDOCS)
ANT_TARGET+=	javadoc
PORTDOCS=	ABOUT.txt README_DOWNLOAD.html THANKS.txt addons.html \
		api_impl build.txt changes.html faq.html features.html \
		javadoc_stylesheet.css properties.html quick_intro.html \
		quick_write.html run.txt
.endif
JARFILE=	${DISTNAME_PREFX}.jar
DESTJARFILE=	${PORTNAME}.jar
PLIST_FILES+=	${JAVAJARDIR:S,^${PREFIX}/,,}/${DESTJARFILE}

do-build:
	@cd ${WRKSRC} && ${ANT} ${ANT_TARGET}

do-install:
	@${ECHO_CMD} -n ">> Installing JAR as ${JAVAJARDIR}/${DESTJARFILE}..."
	@${CP} ${WRKSRC}/build/lib/${JARFILE} ${JAVAJARDIR}/${DESTJARFILE}
	@${ECHO_CMD} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_CMD} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
.for DOCFILE in ${PORTDOCS}
	@${CP} -r ${WRKSRC}/doc/${DOCFILE} ${DOCSDIR}/
	@${ECHO_CMD} -n " ${DOCFILE}"
.endfor
	@${ECHO_CMD} " [ DONE ]"
.endif

.include <bsd.port.mk>
