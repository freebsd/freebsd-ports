# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	yuicompressor
PORTVERSION=	2.4.8
PORTREVISION=	2
CATEGORIES=	www java
#MASTER_SITES=	http://tml.github.io/yui/
MASTER_SITES+=	LOCAL/az
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=	# empty

MAINTAINER=	citrin@citrin.ru
COMMENT=	The Yahoo! JavaScript and CSS Compressor

LICENSE=	BSD3CLAUSE MPL20
LICENSE_COMB=	multi

NO_WRKSUBDIR=	yes

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/yuicompressor %%JAVAJARDIR%%/yuicompressor.jar
SUB_FILES=	yuicompressor

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}.jar ${STAGEDIR}${JAVAJARDIR}/yuicompressor.jar
	${INSTALL_SCRIPT} ${WRKDIR}/yuicompressor ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
