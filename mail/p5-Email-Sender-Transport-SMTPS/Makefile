# $FreeBSD$

PORTNAME=	Email-Sender-Transport-SMTPS
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for Email::Sender::Transport::SMTPS

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Email-Sender>=1.300006:mail/p5-Email-Sender \
	p5-Net-SMTPS>=0.03:mail/p5-Net-SMTPS
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuildtiny

.include <bsd.port.mk>
