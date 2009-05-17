# New ports collection makefile for:	mod_log_data
# Date created:				Sun Oct  5
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	mod_log_data
PORTVERSION=	0.0.3
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://loghttp.sourceforge.net/files/

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Module for Apache 2.0 which logs incoming and outgoing data

MAKE_JOBS_SAFE=  yes

USE_APACHE=	2.0

WRKSRC=		${WRKDIR}/${PORTNAME}

AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

.include <bsd.port.mk>
