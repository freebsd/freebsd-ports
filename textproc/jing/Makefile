# New ports collection makefile for:   jing
# Date created:                3 February 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	jing
PORTVERSION=	2003.01.31
CATEGORIES=	textproc
MASTER_SITES=	http://www.thaiopensource.com/relaxng/
DISTNAME=	${PORTNAME}-bin
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A RELAX NG validator in Java

BROKEN=		"Distfiles not listed in distinfo"

RUN_DEPENDS=	${JAVAJARDIR}/crimson.jar:${PORTSDIR}/textproc/crimson

USE_ZIP=	yes
USE_JAVA=	1.2+
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

NO_BUILD_DEPENDS_JAVA=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.jar ${JAVAJARDIR}

post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${WRKSRC}/*.txt ${DOCSDIR}

.include <bsd.port.mk>
