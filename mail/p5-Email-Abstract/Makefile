# New ports collection makefile for:	p5-Email-Abstract
# Date created:		2004-07-26
# Whom:			Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Email-Abstract
PORTVERSION=	1.0
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Email
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Unified interface to mail representations

BUILD_DEPENDS=	${SITE_PERL}/Module/Pluggable.pm:${PORTSDIR}/devel/p5-Module-Pluggable \
		${SITE_PERL}/Email/Simple.pm:${PORTSDIR}/mail/p5-Email-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Email::Abstract.3 \
		Email::Abstract::EmailMIME.3 \
		Email::Abstract::EmailSimple.3 \
		Email::Abstract::MIMEEntity.3 \
		Email::Abstract::MailInternet.3 \
		Email::Abstract::MailMessage.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} <= 500504
EXTRA_PATCHES=	${PATCHDIR}/5.005-Makefile.PL \
		${PATCHDIR}/5.005-lib::Email::Abstract.pm

post-patch:
	@${RM} ${WRKSRC}/lib/Email/Abstract.pm.orig
.endif
.include <bsd.port.post.mk>
