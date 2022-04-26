PORTNAME=	Email-Sender-Transport-SMTPS
PORTVERSION=	0.04
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for Email::Sender::Transport::SMTPS

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

DEPRECATED=	Deprecated by upstream. Use Email::Sender::Transport::SMTP in mail/p5-Email-Sender instead
EXPIRATION_DATE=2022-04-30

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Email-Sender>=1.300006:mail/p5-Email-Sender \
		p5-Net-SMTPS>=0.03:mail/p5-Net-SMTPS

USES=		perl5
USE_PERL5=	modbuildtiny

NO_ARCH=	yes

.include <bsd.port.mk>
