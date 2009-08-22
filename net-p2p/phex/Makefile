# New ports collection makefile for:	phex
# Date created:				Mon Nov 19 23:48:51 BRST 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	phex
PORTVERSION=	3.4.2.116
CATEGORIES=	net-p2p java
MASTER_SITES=	SF/${PORTNAME}/Phex%20Final%20Releases/Phex%203.4.2
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	A Java multi platform and spyware free gnutella client

USE_JAVA=	yes
JAVA_VERSION=	1.5+
USE_ZIP=	yes
NO_BUILD=	yes

SUB_FILES=	${PORTNAME}.sh
SUB_LIST=	JAVA_VERSION=${JAVA_VERSION}
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

PORTDOCS=	Phex_other.htm \
		Undocumented.htm

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/lib/* ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/docs/readme/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
