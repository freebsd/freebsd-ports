# Created by: Herve Quiroz <hq@FreeBSD.org>
# $FreeBSD$

PORTNAME=	myfaces
PORTVERSION=	1.1.1
PORTREVISION=	2
CATEGORIES=	www devel java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	${PORTNAME}/binaries

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free open source JavaServer(tm) Faces implementation

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
.if !defined(NOPORTDOCS)
PORTDOCS=	javadoc tlddoc LICENSE.txt NOTICE.txt
.endif
JAR_FILES=	myfaces-all.jar myfaces-api.jar myfaces-impl.jar tomahawk.jar
PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar \
		${JAR_FILES:S|^|%%DATADIR%%/|}
PLIST_DIRS=	%%DATADIR%%

NO_STAGE=	yes
.include <bsd.port.pre.mk>

do-install:
	${INSTALL_DATA} ${WRKSRC}/myfaces-all.jar ${JAVAJARDIR}/${PORTNAME}.jar
	@${MKDIR} ${DATADIR}
.for jarfile in ${JAR_FILES}
	${INSTALL_DATA} ${WRKSRC}/${jarfile} ${DATADIR}/${jarfile}
.endfor

.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ${FIND} ${PORTDOCS} -type d -exec ${MKDIR} ${DOCSDIR}/{} \;
	cd ${WRKSRC} && ${FIND} ${PORTDOCS} -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
.endif

.include <bsd.port.post.mk>
