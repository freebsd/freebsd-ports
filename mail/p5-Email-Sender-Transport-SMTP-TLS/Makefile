# Created by: Alexandre Biancalana <ale@biancalanas.net>
# $FreeBSD$

PORTNAME=	Email-Sender-Transport-SMTP-TLS
PORTVERSION=	0.15
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ale@biancalanas.net
COMMENT=	Email::Sender with Net::SMTP::TLS (Eg. Gmail)

LICENSE=	GPLv1
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-Email-Sender>=0.091660:mail/p5-Email-Sender \
		p5-Net-SMTP-TLS-ButMaintained>=0.2:mail/p5-Net-SMTP-TLS-ButMaintained
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
