# New ports collection makefile for:	netmask
# Date created:				19 Novemver 2000
# Whom:					Mike Bristow <mike@urgle.com>
# $FreeBSD$

PORTNAME=	netmask
PORTVERSION=	2.3.3
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	dists/potato/main/source/net
DISTNAME=	netmask_${PORTVERSION}

MAINTAINER=	mike@urgle.com
COMMENT=	Tool for generating terse netmasks in several common formats

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
USE_GETOPT_LONG=yes
USE_AUTOMAKE=	yes
USE_GMAKE=	yes

MAN1=		netmask.1

.include <bsd.port.mk>
