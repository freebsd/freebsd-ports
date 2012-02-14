# New ports collection makefile for:	mod_setenvifplus
# Date created:		2010-11-29
# Whom:			Jim Riggs <ports@christianserving.org>
#
# $FreeBSD$
#

PORTNAME=	mod_setenvifplus
PORTVERSION=	0.13
CATEGORIES=	www
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	modsetenvifplus
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	ports@christianserving.org
COMMENT=	Allows setting environment variables based on request attributes

LICENSE=	AL2

USE_APACHE=	20+
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES
SRC_FILE=	${WRKSRC}/apache2/${MODULENAME}.c

.include <bsd.port.mk>
