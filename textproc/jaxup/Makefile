# Ports collection makefile for:	Jaxup
# Date created:				17 November 2004
# Whom:					Herve Quiroz <hq@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	jaxup
PORTVERSION=	1.01
CATEGORIES=	textproc java
MASTER_SITES=	http://klomp.org/jaxup/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	hq@FreeBSD.org
COMMENT=	Java XUpdate engine

RUN_DEPENDS=	${JAVALIBDIR}/jdom.jar:${PORTSDIR}/java/jdom \
		${JAVALIBDIR}/jaxen-core.jar:${PORTSDIR}/java/jaxen \
		${JAVALIBDIR}/xercesImpl.jar:${PORTSDIR}/textproc/xerces-j

USE_ZIP=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

USE_JAVA=	yes
JAVA_VERSION=	1.3+

USE_ANT=	yes
ALL_TARGET=	jar
.if !defined(NOPORTDOCS)
ALL_TARGET+=	docs
.endif

PLIST_FILES+=	%%JAVAJARDIR%%/${PORTNAME}.jar

.if !defined(NOPORTDOCS)
PORTDOCS=	LICENSE.txt api index.html jaxup_files xupdate-wd.html xupdate-wd_files
.endif

post-extract:
	@${CP} ${FILESDIR}/build.xml ${WRKSRC}/

do-install:
	@${ECHO_MSG} -n ">> Installing JAR files as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${MKDIR} ${JAVAJARDIR}
	@${INSTALL_DATA} ${WRKSRC}/build/lib/${PORTNAME}.jar ${JAVAJARDIR}/
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/build/docs \
	  && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${INSTALL_DATA} ${WRKSRC}/LICENSE.txt ${DOCSDIR}/
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.mk>
