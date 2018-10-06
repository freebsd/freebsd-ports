# $FreeBSD$

PORTNAME=	Net-SMS-Mollie
PORTVERSION=	0.04
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	b.smeelen@ose.nl
COMMENT=	Send SMS messages via the mollie.nl service

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-XML-Simple>=0:textproc/p5-XML-Simple

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
