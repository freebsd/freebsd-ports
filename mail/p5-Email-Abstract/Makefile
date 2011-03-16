# New ports collection makefile for:	p5-Email-Abstract
# Date created:		2004-07-26
# Whom:			Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Email-Abstract
PORTVERSION=	3.004
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Email
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Unified interface to mail representations

RUN_DEPENDS=	p5-Email-Simple>=1.91:${PORTSDIR}/mail/p5-Email-Simple \
		p5-Module-Pluggable>=1.5:${PORTSDIR}/devel/p5-Module-Pluggable \
		p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Email::Abstract.3 \
		Email::Abstract::EmailMIME.3 \
		Email::Abstract::EmailSimple.3 \
		Email::Abstract::MIMEEntity.3 \
		Email::Abstract::MailInternet.3 \
		Email::Abstract::MailMessage.3 \
		Email::Abstract::Plugin.3

.include <bsd.port.mk>
