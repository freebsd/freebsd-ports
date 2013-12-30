# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	htmlcompressor
PORTVERSION=	1.5.3
PORTREVISION=	1
CATEGORIES=	www java
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}-${PORTVERSION}.jar
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTML/XML Compressor

LICENSE=	APACHE20

NO_WRKSUBDIR=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	yes

PLIST_FILES=	bin/htmlcompressor %%JAVAJARDIR%%/htmlcompressor.jar
SUB_FILES=	htmlcompressor

NO_STAGE=	yes
.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${JAVAJARDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME} ${JAVAJARDIR}/htmlcompressor.jar
	${INSTALL_SCRIPT} ${WRKDIR}/htmlcompressor ${PREFIX}/bin

.include <bsd.port.post.mk>
