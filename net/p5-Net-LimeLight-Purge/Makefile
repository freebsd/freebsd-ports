# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Net-LimeLight-Purge
PORTVERSION=	0.03
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	LimeLight Purge Service API

RUN_DEPENDS=	p5-DateTime-Format-ISO8601>=0.06:${PORTSDIR}/devel/p5-DateTime-Format-ISO8601 \
		p5-Moose>=0.72:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-AttributeHelpers>=0.14:${PORTSDIR}/devel/p5-MooseX-AttributeHelpers \
		p5-SOAP-Lite>=0.710.08:${PORTSDIR}/net/p5-SOAP-Lite

USES=		perl5
USE_PERL5=	configure

MAN3=		Net::LimeLight::Purge.3 \
		Net::LimeLight::Purge::Request.3 \
		Net::LimeLight::Purge::StatusResponse.3

NO_STAGE=	yes
.include <bsd.port.mk>
