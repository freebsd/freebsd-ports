# New ports collection makefile for:	netmask
# Date created:				19 Novemver 2000
# Whom:					Mike Bristow <mike@urgle.com>
# $FreeBSD$

PORTNAME=	netmask
PORTVERSION=	2.3.3
CATEGORIES=	net
MASTER_SITES=	http://ftp.debian.org/debian/dists/potato/main/source/net/
DISTNAME=	netmask_${PORTVERSION}

MAINTAINER=	mike@urgle.com

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
USE_AUTOMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"

USE_GMAKE=	yes

MAN1=		netmask.1

.include <bsd.port.mk>
