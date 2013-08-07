# $FreeBSD$

PORTNAME=	Email-Abstract
PORTVERSION=	3.005
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Email
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Unified interface to mail representations

RUN_DEPENDS=	p5-Email-Simple>=1.91:${PORTSDIR}/mail/p5-Email-Simple \
		p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Email::Abstract.3 \
		Email::Abstract::EmailMIME.3 \
		Email::Abstract::EmailSimple.3 \
		Email::Abstract::MIMEEntity.3 \
		Email::Abstract::MailInternet.3 \
		Email::Abstract::MailMessage.3 \
		Email::Abstract::Plugin.3

.include <bsd.port.mk>
