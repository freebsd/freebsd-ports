# New ports collection makefile for:	mod_bw
# Date created:				Sep 11 2005
# Whom:					Clement Laforet <clement@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_bw
PORTVERSION=	0.6
CATEGORIES=	www
MASTER_SITES=	http://www.ivn.cl/apache/
DISTNAME=	bw_mod-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	apache2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Bandwidth and Connection control per Virtual Host or Directory

USE_APACHE=	20+
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES

SRC_FILE=	bw_mod-0.6.c
PORTDOCS=	APACHE2-LICENSE LICENSE bw_mod-0.6.txt

post-install:
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && \
		${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}

.include <bsd.port.mk>
