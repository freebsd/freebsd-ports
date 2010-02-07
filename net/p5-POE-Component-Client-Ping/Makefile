# New ports collection makefile for:	POE-Component-Client-Ping
# Date created:		10 Dec 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Client-Ping
PORTVERSION=	1.163
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	POE component for non-blocking/concurrent ICMP ping

RUN_DEPENDS=	p5-POE>=1.0070:${PORTSDIR}/devel/p5-POE
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::Component::Client::Ping.3

.include <bsd.port.mk>
