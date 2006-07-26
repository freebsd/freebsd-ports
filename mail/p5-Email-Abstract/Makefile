# New ports collection makefile for:	p5-Email-Abstract
# Date created:		2004-07-26
# Whom:			Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Email-Abstract
PORTVERSION=	2.13
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Email
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Unified interface to mail representations

BUILD_DEPENDS=	p5-Class-ISA>=0.20:${PORTSDIR}/devel/p5-Class-ISA \
		p5-Email-Simple>=1.91:${PORTSDIR}/mail/p5-Email-Simple \
		p5-Module-Pluggable>=1.5:${PORTSDIR}/devel/p5-Module-Pluggable
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Email::Abstract.3 \
		Email::Abstract::EmailMIME.3 \
		Email::Abstract::EmailSimple.3 \
		Email::Abstract::MIMEEntity.3 \
		Email::Abstract::MailInternet.3 \
		Email::Abstract::MailMessage.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500600
IGNORE=		requires Perl 5.6 or later. Please install lang/perl5 or lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
