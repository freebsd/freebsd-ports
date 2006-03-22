# New ports collection makefile for:	nux
# Date created:		2004-10-28
# Whom:			Herve Quiroz <hq@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nux
PORTVERSION=	1.4.1
PORTEPOCH=	1
CATEGORIES=	textproc java
MASTER_SITES=	http://dsd.lbl.gov/nux-download/releases/

MAINTAINER=	hq@FreeBSD.org
COMMENT=	Small open-source XQuery extension of the XOM library

RUN_DEPENDS=	${JAVALIBDIR}/xom.jar:${PORTSDIR}/textproc/xom \
		${JAVALIBDIR}/saxon8.jar:${PORTSDIR}/textproc/saxon-devel

OPTIONS=	XQUERY_TOOL "Install the XQuery command-line tool" on

USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

.if defined(WITH_XQUERY_TOOL)
RUN_DEPENDS+=	${JAVALIBDIR}/getopt.jar:${PORTSDIR}/java/java-getopt \
		classpath:${PORTSDIR}/java/javavmwrapper
.endif

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar
.if defined(WITH_XQUERY_TOOL)
PLIST_FILES+=	bin/fire-xquery
.endif
.if !defined(NOPORTDOCS)
PORTDOCS=	api changelog.html cvs.html dependencies.html \
		gettingstarted.html images index.html license.html licenses \
		mailing.html readme.html related.html style.css todo.html
.endif

.if defined(WITH_XQUERY_TOOL)
SUB_FILES=	fire-xquery.sh
.endif

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${MKDIR} ${JAVAJARDIR}
	@${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME}.jar ${JAVAJARDIR}/
	@${ECHO_MSG} " [ DONE ]"
.if defined(WITH_XQUERY_TOOL)
	@${ECHO_MSG} -n ">> Installing XQuery command-line tool as ${PREFIX}/bin/fire-xquery..."
	@${INSTALL_SCRIPT} ${WRKDIR}/fire-xquery.sh ${PREFIX}/bin/fire-xquery
	@${ECHO_MSG} " [ DONE ]"
.endif
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@cd ${WRKSRC}/doc/ && ${FIND} ${PORTDOCS} -type d -exec ${MKDIR} ${DOCSDIR}/{} \;
	@cd ${WRKSRC}/doc/ && ${FIND} ${PORTDOCS} -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.post.mk>
