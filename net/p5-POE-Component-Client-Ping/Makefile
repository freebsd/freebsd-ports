# New ports collection makefile for:	POE-Component-Client-Ping
# Date created:		10 Dec 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Client-Ping
PORTVERSION=	1.04
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	POE
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	POE component for non-blocking/concurrent ICMP ping

BUILD_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::Component::Client::Ping.3

.include <bsd.port.mk>
