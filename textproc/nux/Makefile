# New ports collection makefile for:	nux
# Date created:		2004-10-28
# Whom:			Herve Quiroz <hq@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nux
PORTVERSION=	1.0a5
CATEGORIES=	textproc java
MASTER_SITES=	http://dsd.lbl.gov/nux-download/snapshots/

MAINTAINER=	hq@FreeBSD.org
COMMENT=	Small open-source XQuery extension of the XOM library

RUN_DEPENDS=	${JAVALIBDIR}/xom.jar:${PORTSDIR}/textproc/xom \
		${JAVALIBDIR}/saxon8.jar:${PORTSDIR}/textproc/saxon-devel

OPTIONS=	VALIDATION_TOOL "Install the XML Schema validation tool" on

USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

.if defined(WITH_VALIDATION_TOOL)
RUN_DEPENDS+=	${JAVALIBDIR}/getopt.jar:${PORTSDIR}/java/java-getopt \
		classpath:${PORTSDIR}/java/javavmwrapper
VALIDATION_TOOL=fire-validate
.endif

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar
.if defined(WITH_VALIDATION_TOOL)
PLIST_FILES+=	bin/${VALIDATION_TOOL}
.endif
.if !defined(NOPORTDOCS)
PORTDOCS=	api bugs.html changelog.html cvs.html dependencies.html \
		gettingstarted.html images index.html install.html \
		license.html licenses mailing.html readme.html \
		relatedwork.html style.css todo.html tutorials.html
.endif

.if defined(WITH_VALIDATION_TOOL)
do-configure:
	${SED} -e 's,%%LOCALBASE%%,${LOCALBASE},g ; s,%%JAVA%%,${JAVA},g' \
	  ${FILESDIR}/${VALIDATION_TOOL}.sh >${WRKSRC}/${VALIDATION_TOOL}
.endif

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${MKDIR} ${JAVAJARDIR}
	@${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME}.jar ${JAVAJARDIR}/
	@${ECHO_MSG} " [ DONE ]"
.if defined(WITH_VALIDATION_TOOL)
	@${ECHO_MSG} -n ">> Installing validation tool as ${PREFIX}/bin/${VALIDATION_TOOL}..."
	@${INSTALL_SCRIPT} ${WRKSRC}/${VALIDATION_TOOL} ${PREFIX}/bin/
	@${ECHO_MSG} " [ DONE ]"
.endif
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/doc/ && ${FIND} ${PORTDOCS} \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} > /dev/null 2>&1
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.post.mk>
