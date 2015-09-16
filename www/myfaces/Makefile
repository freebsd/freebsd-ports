# Created by: Herve Quiroz <hq@FreeBSD.org>
# $FreeBSD$

PORTNAME=	myfaces
PORTVERSION=	1.1.1
PORTREVISION=	2
CATEGORIES=	www devel java
MASTER_SITES=	APACHE/${PORTNAME}/binaries

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free open source JavaServer(tm) Faces implementation

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
USES=		cpe
CPE_VENDOR=	apache

OPTIONS_DEFINE=	DOCS

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
PORTDOCS=	javadoc tlddoc LICENSE.txt NOTICE.txt
JAR_FILES=	myfaces-all.jar myfaces-api.jar myfaces-impl.jar tomahawk.jar
PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar \
		${JAR_FILES:S|^|%%DATADIR%%/|}

do-install:
	${INSTALL_DATA} ${WRKSRC}/myfaces-all.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for jarfile in ${JAR_FILES}
	${INSTALL_DATA} ${WRKSRC}/${jarfile} ${STAGEDIR}${DATADIR}/${jarfile}
.endfor

	cd ${WRKSRC} && ${FIND} ${PORTDOCS} -type d -exec ${MKDIR} ${STAGEDIR}${DOCSDIR}/{} \;
	cd ${WRKSRC} && ${FIND} ${PORTDOCS} -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR}/{} \;

.include <bsd.port.mk>
