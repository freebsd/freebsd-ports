# New ports collection makefile for:	POE-Component-Client-Keepalive
# Date created:	   24 June 2005
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Client-Keepalive
PORTVERSION=	0.2630
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0+$//}

MAINTAINER=	skv@FreeBSD.org
COMMENT=	POE component for managing connections, with keep-alive

BUILD_DEPENDS=	p5-POE>=1.280:${PORTSDIR}/devel/p5-POE \
		p5-POE-Component-Client-DNS>=1.0510:${PORTSDIR}/dns/p5-POE-Component-Client-DNS \
		p5-Net-IP>=1.25:${PORTSDIR}/net-mgmt/p5-Net-IP
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::Component::Client::Keepalive.3 \
		POE::Component::Connection::Keepalive.3

.include <bsd.port.mk>
