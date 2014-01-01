# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	closure-compiler
PORTVERSION=	20120430
CATEGORIES=	www java
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	compiler-${PORTVERSION}

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	Closure Compiler

LICENSE=	APACHE20

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
SUB_FILES=	closure-compiler
SUB_LIST=	JAVA="${JAVA}"
USE_JAVA=	yes

PLIST_DIRSTRY=	%%DATADIR%%
PLIST_FILES=	bin/closure-compiler \
		%%DATADIR%%/compiler.jar

NO_STAGE=	yes
do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/compiler.jar ${DATADIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/closure-compiler ${PREFIX}/bin/

.include <bsd.port.mk>
