# New ports collection makefile for:	closure-compiler
# Date created:		2009-11-14
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	closure-compiler
PORTVERSION=	20100917
CATEGORIES=	www java
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	compiler-${PORTVERSION}

MAINTAINER=	kimelto@gmail.com
COMMENT=	Closure Compiler

LICENSE=	ASL

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
SUB_FILES=	closure-compiler
SUB_LIST=	JAVA="${JAVA}"
USE_JAVA=	yes

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/compiler.jar ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/closure-compiler ${PREFIX}/bin

.include <bsd.port.mk>
