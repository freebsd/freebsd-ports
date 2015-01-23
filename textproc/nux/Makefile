# Created by: Herve Quiroz <hq@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nux
PORTVERSION=	1.6
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	textproc java
MASTER_SITES=	http://dsd.lbl.gov/nux-download/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small open-source XQuery extension of the XOM library

RUN_DEPENDS=	${JAVALIBDIR}/xom.jar:${PORTSDIR}/textproc/xom \
		${JAVALIBDIR}/saxon9.jar:${PORTSDIR}/textproc/saxon-devel

OPTIONS_DEFINE=	XQUERY_TOOL DOCS
XQUERY_TOOL_DESC=	Install the XQuery command-line tool
OPTIONS_DEFAULT=	XQUERY_TOOL

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXQUERY_TOOL}
RUN_DEPENDS+=	${JAVALIBDIR}/java-getopt.jar:${PORTSDIR}/java/java-getopt
.endif

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar
.if ${PORT_OPTIONS:MXQUERY_TOOL}
PLIST_FILES+=	bin/fire-xquery
.endif

PORTDOCS=	api changelog.html cvs.html dependencies.html \
		gettingstarted.html images index.html license.html licenses \
		mailing.html readme.html related.html style.css todo.html

.if ${PORT_OPTIONS:MXQUERY_TOOL}
SUB_FILES=	fire-xquery.sh
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME}.jar ${STAGEDIR}${JAVAJARDIR}
.if ${PORT_OPTIONS:MXQUERY_TOOL}
	${INSTALL_SCRIPT} ${WRKDIR}/fire-xquery.sh ${STAGEDIR}${PREFIX}/bin/fire-xquery
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
