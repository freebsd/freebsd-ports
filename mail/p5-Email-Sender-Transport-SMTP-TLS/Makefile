# Created by: Alexandre Biancalana <ale@biancalanas.net>
# $FreeBSD$

PORTNAME=	Email-Sender-Transport-SMTP-TLS
PORTVERSION=	0.14
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ale@biancalanas.net
COMMENT=	Email::Sender with Net::SMTP::TLS (Eg. Gmail)

RUN_DEPENDS=	p5-Email-Sender>=0.091660:${PORTSDIR}/mail/p5-Email-Sender \
		p5-Net-SMTP-TLS-ButMaintained>=0.2:${PORTSDIR}/mail/p5-Net-SMTP-TLS-ButMaintained
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Email::Sender::Transport::SMTP::TLS.3

.include <bsd.port.mk>
