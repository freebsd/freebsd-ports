# New ports collection makefile for:   Trang
# Date created:                22 January 2004
# Whom:                        Kimura Fuyuki <fuyuki@nigredo.org>
#
# $FreeBSD$
#

PORTNAME=	trang
PORTVERSION=	2003.06.19
CATEGORIES=	textproc java
MASTER_SITES=	http://www.thaiopensource.com/download/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-format schema converter based on RELAX NG

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	copying.txt trang-manual.html
.endif

SUB_FILES=	trang.sh
PLIST_FILES=	%%JAVAJARDIR%%/trang.jar bin/trang

do-install:
	${INSTALL_DATA} ${WRKSRC}/trang.jar ${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/trang.sh ${PREFIX}/bin/trang
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
