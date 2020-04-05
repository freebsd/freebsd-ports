# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	closure-compiler
PORTVERSION=	20180805
CATEGORIES=	www java
MASTER_SITES=	http://dl.google.com/closure-compiler/
DISTNAME=	compiler-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Closure Compiler

LICENSE=	APACHE20

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
SUB_FILES=	closure-compiler
SUB_LIST=	JAVA="${JAVA}" PORTVERSION=${PORTVERSION}
USE_JAVA=	yes

PLIST_FILES=	bin/closure-compiler \
		${DATADIR}/closure-compiler-v${PORTVERSION}.jar

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/closure-compiler-v${PORTVERSION}.jar ${STAGEDIR}${DATADIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/closure-compiler ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
