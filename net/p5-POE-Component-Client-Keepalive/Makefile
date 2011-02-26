# New ports collection makefile for:	POE-Component-Client-Keepalive
# Date created:	   24 June 2005
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Client-Keepalive
PORTVERSION=	0.2660
CATEGORIES=	net perl5
MASTER_SITES=	CPAN/${PORTNAME:C/-.*//}/RCAPUTO
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0+$//}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	POE component for managing connections, with keep-alive

BUILD_DEPENDS=	p5-POE>=1.299:${PORTSDIR}/devel/p5-POE \
		p5-POE-Component-Resolver>=0.911:${PORTSDIR}/dns/p5-POE-Component-Resolver \
		p5-Net-IP>=1.25:${PORTSDIR}/net-mgmt/p5-Net-IP
RUN_DEPENDS=	${BUILD_DEPENDS}

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

PERL_CONFIGURE=	yes

MAN3=		POE::Component::Client::Keepalive.3 \
		POE::Component::Connection::Keepalive.3

.include <bsd.port.mk>
