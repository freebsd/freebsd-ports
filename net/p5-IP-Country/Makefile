# New ports collection makefile for:	net/p5-IP-Countries
# Date created:				20 June 2005
# Whom:					dikshie <dikshie@lapi.itb.ac.id>
#
# $FreeBSD$
#

PORTNAME=	IP-Country
PORTVERSION=	2.20
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/N/NW/NWETTERS
PKGNAMEPREFIX=	p5-

MAINTAINER=	dikshie@lapi.itb.ac.id
COMMENT=	Fast lookup of country codes from IP addresses

BUILD_DEPENDS=	${SITE_PERL}/Geography/Countries.pm:${PORTSDIR}/misc/p5-Geography-Countries
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		ip2cc.1
MAN3=		IP::Authority.3 \
		IP::Country::Fast.3 \
		IP::Country::MaxMind.3 \
		IP::Country::Medium.3 \
		IP::Country::Slow.3 \
		IP::Country.3

.include <bsd.port.mk>
