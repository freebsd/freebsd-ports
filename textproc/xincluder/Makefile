# Created by: Ernst de Haan <znerd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xincluder
PORTVERSION=	1.0.d11
PORTREVISION=	5
CATEGORIES=	textproc java
MASTER_SITES=	ftp://ftp.ibiblio.org/pub/languages/java/javafaq/
DISTNAME=	${PORTNAME}-1.0d11

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java-based XInclude processors

RUN_DEPENDS=	${JAVALIBDIR}/jdom.jar:${PORTSDIR}/java/jdom \
		${JAVALIBDIR}/xercesImpl.jar:${PORTSDIR}/textproc/xerces-j \
		java:${PORTSDIR}/java/javavmwrapper

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

SUFFIXES=	-sax -dom -jdom
PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar bin/xincluder ${SUFFIXES:S,^,bin/xincluder,}
.if !defined(NOPORTDOCS)
PORTDOCS=	apidoc index.html
.endif
SUB_FILES=	xincluder.sh

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.jar ${STAGEDIR}${JAVAJARDIR}/
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} -n ">> Installing scripts in ${PREFIX}/bin..."
	@${ECHO_MSG} -n " xincluder"
	@${INSTALL_SCRIPT} ${WRKDIR}/xincluder.sh ${STAGEDIR}${PREFIX}/bin/xincluder
.for suffix in ${SUFFIXES}
	@${ECHO_MSG} -n " xincluder${suffix}"
	@${LN} -s xincluder ${STAGEDIR}${PREFIX}/bin/xincluder${suffix}
.endfor
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@cd ${WRKSRC} \
	  && ${FIND} ${PORTDOCS} -type d -exec ${MKDIR} ${STAGEDIR}${DOCSDIR}/{} \; \
	  && ${FIND} ${PORTDOCS} -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR}/{} \;
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.mk>
