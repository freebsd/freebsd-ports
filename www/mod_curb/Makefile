# New ports collection makefile for:	mod_curb
# Date created:				Sep 7 2005
# Whom:					Clement Laforet <clement@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_curb
PORTVERSION=	1.1
CATEGORIES=	www
MASTER_SITES=	http://www.steve.org.uk/Software/mod_curb/
DISTNAME=	${PORTNAME:C/_/-/}-${PORTVERSION}
DIST_SUBDIR=	apache

MAINTAINER=	apache@FreeBSD.org
COMMENT=	A per-server bandwidth limiter module for Apache 1.3

MAKE_JOBS_SAFE=  yes

USE_APACHE=	13

AP_FAST_BUILD=	YES
AP_GENPLIST=	YES
PORTDOCS=	README

post-install:
.ifndef NOPORTDOCS
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
