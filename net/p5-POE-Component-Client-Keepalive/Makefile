# New ports collection makefile for:	POE-Component-Client-Keepalive
# Date created:	   24 June 2005
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Client-Keepalive
PORTVERSION=	0.04
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	POE
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	POE component for managing connections, with keep-alive

BUILD_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/POE/Component/Client/DNS.pm:${PORTSDIR}/dns/p5-POE-Component-Client-DNS \
		${SITE_PERL}/POE/Component/SSLify.pm:${PORTSDIR}/security/p5-POE-Component-SSLify
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::Component::Client::Client-Keepalive.3 \
		POE::Component::Client::Conn-Keepalive.3

.include <bsd.port.mk>
