# New ports collection makefile for:	xmlpull
# Date created:		2004-03-30
# Whom:			Herve Quiroz <herve.quiroz@esil.univ-mrs.fr>
#
# $FreeBSD$
#

PORTNAME=	xmlpull
PORTVERSION=	1.1.3.4a
PORTREVISION=	1
CATEGORIES=	textproc java
MASTER_SITES=	http://voodoo.oberon.net/download/ \
		http://www.xmlpull.org/v1/download/
DISTNAME=	${DISTNAME_PREFX}_src
EXTRACT_SUFX=	.tgz

MAINTAINER=	hq@FreeBSD.org
COMMENT=	Common API for XML Pull Parsing (XmlPull)

USE_JAVA=	yes
JAVA_VERSION=	1.3+
DISTNAME_PREFX=	${PORTNAME}_${PORTVERSION:S/./_/g}
WRKSRC=		${WRKDIR}/${DISTNAME_PREFX}

USE_ANT=	yes
ALL_TARGET=	jar
.if !defined(NOPORTDOCS)
ALL_TARGET+=	apidoc
PORTDOCS=	ABOUT.txt README_DOWNLOAD.html THANKS.txt addons.html \
		api build.txt changes.html faq.html features.html \
		javadoc_stylesheet.css properties.html quick_intro.html \
		quick_write.html run.txt
.endif
JARFILE=	${DISTNAME_PREFX}.jar
DESTJARFILE=	${PORTNAME}.jar
PLIST_FILES+=	%%JAVAJARDIR%%/${DESTJARFILE}

.include <bsd.port.pre.mk>

JDK_API!=	(${FIND} -s ${LOCALBASE}/share/doc/jdk1.? -maxdepth 1 -name api -type d 2>/dev/null || ${TRUE}) | ${TAIL} -n 1
.if ${JDK_API} != ""
MAKE_ARGS+=	-Djdk.api=${JDK_API}
.endif

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${DESTJARFILE}..."
	@${INSTALL_DATA} ${WRKSRC}/build/lib/${JARFILE} ${JAVAJARDIR}/${DESTJARFILE}
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@cd ${WRKSRC}/doc \
	  && ${FIND} ${PORTDOCS} -type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
	  && ${FIND} ${PORTDOCS} -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.post.mk>
