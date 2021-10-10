# Created by: Herve Quiroz <hq@FreeBSD.org>

PORTNAME=	myfaces
PORTVERSION=	1.1.1
PORTREVISION=	2
CATEGORIES=	www devel java
MASTER_SITES=	https://archive.apache.org/dist/${PORTNAME}/binaries/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free open source JavaServer(tm) Faces implementation

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	Unsupported by upstream, released in 2005
EXPIRATION_DATE=2022-03-31

USE_JAVA=	yes
NO_BUILD=	yes
NO_ARCH=	yes
USES=		cpe
CPE_VENDOR=	apache

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
PORTDOCS=	javadoc tlddoc LICENSE.txt NOTICE.txt
JAR_FILES=	myfaces-all.jar myfaces-api.jar myfaces-impl.jar tomahawk.jar
PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar \
		${JAR_FILES:S|^|%%DATADIR%%/|}

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_DATA} ${WRKSRC}/myfaces-all.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for jarfile in ${JAR_FILES}
	${INSTALL_DATA} ${WRKSRC}/${jarfile} ${STAGEDIR}${DATADIR}/${jarfile}
.endfor

do-install-DOCS-on:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
