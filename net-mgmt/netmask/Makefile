# New ports collection makefile for:	netmask
# Date created:				19 Novemver 2000
# Whom:					Mike Bristow <mike@urgle.com>
# $FreeBSD$

PORTNAME=	netmask
PORTVERSION=	2.3.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	dists/potato/main/source/net
DISTNAME=	netmask_${PORTVERSION}

MAINTAINER=	mike@urgle.com
COMMENT=	Tool for generating terse netmasks in several common formats

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
USE_AUTOMAKE=	yes
USE_GMAKE=	yes

MAN1=		netmask.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500041
LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"
.endif

.include <bsd.port.post.mk>
