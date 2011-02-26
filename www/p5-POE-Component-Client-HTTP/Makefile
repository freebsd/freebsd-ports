# New ports collection makefile for:	POE-Component-Client-HTTP
# Date created:		10 Dec 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Client-HTTP
PORTVERSION=	0.9420
CATEGORIES=	www perl5
MASTER_SITES=	CPAN/${PORTNAME:C/-.*//}/RCAPUTO
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0$//}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	POE component for non-blocking/concurrent HTTP queries

BUILD_DEPENDS=	p5-POE>=1.299:${PORTSDIR}/devel/p5-POE \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-URI>=1.37:${PORTSDIR}/net/p5-URI \
		p5-POE-Component-Client-Keepalive>=0.2660:${PORTSDIR}/net/p5-POE-Component-Client-Keepalive \
		p5-Test-POE-Server-TCP>=1.14:${PORTSDIR}/devel/p5-Test-POE-Server-TCP \
		p5-Test-Simple>=0.96:${PORTSDIR}/devel/p5-Test-Simple \
		p5-Socket-GetAddrInfo>=0.19:${PORTSDIR}/net/p5-Socket-GetAddrInfo
RUN_DEPENDS:=	${BUILD_DEPENDS}

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

PERL_CONFIGURE=	yes

MAN3=		POE::Component::Client::HTTP.3 \
		POE::Component::Client::HTTP::Request.3 \
		POE::Component::Client::HTTP::RequestFactory.3 \
		POE::Filter::HTTPChunk.3 POE::Filter::HTTPHead.3

.include <bsd.port.mk>
