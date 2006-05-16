# New ports collection makefile for:	mod_bw
# Date created:				Sep 11 2005
# Whom:					Clement Laforet <clement@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_bw
PORTVERSION=	0.7
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	bwmod
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	apache2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Bandwidth and Connection control per Virtual Host or Directory

WRKSRC=		${WRKDIR}/mod_bw
USE_APACHE=	20+
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES

SRC_FILE=	mod_bw.c
PORTDOCS=	LICENSE mod_bw.txt

post-install:
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && \
		${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}

.include <bsd.port.mk>
