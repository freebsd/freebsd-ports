# New ports collection makefile for:	mod_bw
# Date created:				Sep 11 2005
# Whom:					Clement Laforet <clement@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_bw
PORTVERSION=	0.8
CATEGORIES=	www
MASTER_SITES=	http://www.ivn.cl/apache/files/source/
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	apache2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Bandwidth and Connection control per Virtual Host or Directory

MAKE_JOBS_SAFE=  yes

WRKSRC=		${WRKDIR}/mod_bw
USE_APACHE=	20+
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES

SRC_FILE=	mod_bw.c
PORTDOCS=	LICENSE mod_bw.txt

post-install:
.ifndef NOPORTDOCS
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && \
		${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
