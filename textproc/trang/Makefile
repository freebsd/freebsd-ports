# New ports collection makefile for:   Trang
# Date created:                22 January 2004
# Whom:                        Kimura Fuyuki <fuyuki@nigredo.org>
#
# $FreeBSD$
#

PORTNAME=	trang
PORTVERSION=	2003.06.19
CATEGORIES=	textproc
MASTER_SITES=	http://www.thaiopensource.com/download/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}

MAINTAINER=	fuyuki@nigredo.org
COMMENT=	Multi-format schema converter based on RELAX NG

USE_ZIP=	yes
USE_JAVA=	1.4+
PORTDOCS=	copying.txt trang-manual.html

NO_BUILD_DEPENDS_JAVA=	yes

do-build:
	${ECHO_CMD} '#/bin/sh' >${WRKSRC}/trang
	${ECHO_CMD} 'exec javavm -jar ${JAVAJARDIR}/trang.jar "$$@"' \
		>>${WRKSRC}/trang

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.jar ${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/trang ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
