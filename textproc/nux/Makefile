# Created by: Herve Quiroz <hq@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nux
PORTVERSION=	1.6
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	textproc java
MASTER_SITES=	http://dst.lbl.gov/ACSSoftware/nux/nux-download/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small open-source XQuery extension of the XOM library

RUN_DEPENDS=	${JAVALIBDIR}/xom.jar:textproc/xom \
		${JAVALIBDIR}/saxon9.jar:textproc/saxon-devel

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar
PORTDOCS=	api changelog.html cvs.html dependencies.html \
		gettingstarted.html images index.html license.html licenses \
		mailing.html readme.html related.html style.css todo.html

OPTIONS_DEFINE=		XQUERY_TOOL DOCS
OPTIONS_DEFAULT=	XQUERY_TOOL

XQUERY_TOOL_DESC=	Install the XQuery command-line tool
XQUERY_TOOL_RUN_DEPENDS=${JAVALIBDIR}/java-getopt.jar:java/java-getopt
XQUERY_TOOL_PLIST_FILES=bin/fire-xquery
XQUERY_TOOL_SUB_FILES=	fire-xquery.sh

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME}.jar ${STAGEDIR}${JAVAJARDIR}

do-install-XQUERY_TOOL-on:
	${INSTALL_SCRIPT} ${WRKDIR}/fire-xquery.sh ${STAGEDIR}${PREFIX}/bin/fire-xquery

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
