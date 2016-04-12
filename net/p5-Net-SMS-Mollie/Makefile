# $FreeBSD$

PORTNAME=	Net-SMS-Mollie
PORTVERSION=	0.04
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	b.smeelen@ose.nl
COMMENT=	Send SMS messages via the mollie.nl service

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-XML-Simple>=0:textproc/p5-XML-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
