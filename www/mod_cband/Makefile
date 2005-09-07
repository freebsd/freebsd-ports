# New ports collection makefile for:	mod_cband
# Date created:				Sep 7 2005
# Whom:					Clement Laforet <clement@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_cband
PORTVERSION=	0.9
CATEGORIES=	www
MASTER_SITES=	http://dembol.nasa.pl/download/
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	apache2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	A per-virtualhost bandwidth limiter module for Apache 2

WRKSRC=		${WRKDIR}/${PORTNAME}
WANT_APACHE=	2
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/apache20/Makefile.modules.3rd"
.include <bsd.port.post.mk>
