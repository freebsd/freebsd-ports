# New ports collection makefile for:	xpp3
# Date created:		2004-04-02
# Whom:			Herve Quiroz <herve.quiroz@esil.univ-mrs.fr>
#
# $FreeBSD$
#

PORTNAME=	xpp3
PORTVERSION=	1.1.3.4d.b4
CATEGORIES=	textproc java
MASTER_SITES=	http://www.extreme.indiana.edu/dist/java-repository/xpp3/distributions/
DISTNAME=	${DISTNAME_PREFX}_src
EXTRACT_SUFX=	.tgz

MAINTAINER=	hq@FreeBSD.org
COMMENT=	XML Pull Parser 3rd Edition (XPP3)

BUILD_DEPENDS=	${ANT}:${PORTSDIR}/devel/apache-ant

USE_JAVA=	yes
JAVA_VERSION=	1.3+

DISTNAME_PREFX=	${PORTNAME}-${PORTVERSION:S/d.b/d_b/g}
WRKSRC=		${WRKDIR}/${DISTNAME_PREFX}

ANT?=		${LOCALBASE}/bin/ant
ANT_TARGET=	jar
.if !defined(NOPORTDOCS)
ANT_TARGET+=	javadoc
PORTDOCS=	api_impl ABOUT.txt THANKS.txt TODO.html build.txt changes.html faq.html
.endif
JARFILE=	${DISTNAME_PREFX}.jar
DESTJARFILE=	${PORTNAME}.jar
PLIST_FILES+=	${JAVAJARDIR:S,^${PREFIX}/,,}/${DESTJARFILE}

do-build:
	@cd ${WRKSRC} && ${ANT} ${ANT_TARGET}

do-install:
	@${ECHO_CMD} -n ">> Installing JAR as ${JAVAJARDIR}/${DESTJARFILE}..."
	@${MKDIR} ${JAVAJARDIR}
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
