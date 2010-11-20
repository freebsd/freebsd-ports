# New ports collection makefile for:	htmlcompressor
# Date created:	   20 Nov 2010
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	htmlcompressor
PORTVERSION=	0.9.4
CATEGORIES=	www java
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	skv@FreeBSD.org
COMMENT=	HTML/XML Compressor

LICENSE=	ASL
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	yes

PLIST_FILES=	bin/htmlcompressor %%DATADIR%%/htmlcompressor.jar
PLIST_DIRS=	%%DATADIR%%
SUB_FILES=	htmlcompressor

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/build/htmlcompressor-${PORTVERSION}.jar ${DATADIR}/htmlcompressor.jar
	${INSTALL_SCRIPT} ${WRKDIR}/htmlcompressor ${PREFIX}/bin

.include <bsd.port.post.mk>
