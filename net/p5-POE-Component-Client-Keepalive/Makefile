# New ports collection makefile for:	POE-Component-Client-Keepalive
# Date created:	   24 June 2005
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Client-Keepalive
PORTVERSION=	0.2710
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RCAPUTO
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0$//}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	POE component for managing connections, with keep-alive

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Net-IP-Minimal>=0.02:${PORTSDIR}/net/p5-Net-IP-Minimal  \
		p5-POE>=1.311:${PORTSDIR}/devel/p5-POE \
		p5-POE-Component-Resolver>=0.917:${PORTSDIR}/dns/p5-POE-Component-Resolver
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::Component::Client::Keepalive.3 \
		POE::Component::Connection::Keepalive.3

.include <bsd.port.mk>
