# New ports collection makefile for:	p5-Email-Simple-Creator
# Date created:				Jul 11 2004
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Email-Simple-Creator
PORTVERSION=	1.424
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A constructor to Email::Simple for creating messages from scratch

BUILD_DEPENDS=	${SITE_PERL}/Email/Simple.pm:${PORTSDIR}/mail/p5-Email-Simple \
		${SITE_PERL}/Email/Date.pm:${PORTSDIR}/mail/p5-Email-Date
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Email::Simple::Creator.3

.include <bsd.port.mk>
