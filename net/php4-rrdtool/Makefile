# New ports collection makefile for:	php4-rrdtool
# Date created:				26 Aug 2004
# Whom:					mat
#
# $FreeBSD$
#

PORTNAME=	rrdtool
PORTVERSION=	1.05
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL} http://www.joeym.net/
MASTER_SITE_SUBDIR=	mat
PKGNAMEPREFIX=	php4-
DISTNAME=	${UNIQUENAME}-${PORTVERSION}

MAINTAINER=	mat@FreeBSD.org
COMMENT=	A php/rrdtool glue

LIB_DEPENDS=	rrd:${PORTSDIR}/net/rrdtool

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${UNIQUENAME}-${PORTVERSION}

USE_PHP=	yes
USE_PHPEXT=	yes

.include <bsd.port.mk>
