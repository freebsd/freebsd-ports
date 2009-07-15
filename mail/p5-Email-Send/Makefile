# New ports collection makefile for:	mail/p5-Email-Send
# Date created:				27 December 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Email-Send
PORTVERSION=	2.198
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Email::Send - Simply Sending Email

BUILD_DEPENDS=	p5-Class-Accessor>=0.19:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Email-Address>=1.80:${PORTSDIR}/mail/p5-Email-Address \
		p5-Email-Simple>=1.92:${PORTSDIR}/mail/p5-Email-Simple \
		p5-Module-Pluggable>=2.97:${PORTSDIR}/devel/p5-Module-Pluggable \
		p5-Return-Value>=1.28:${PORTSDIR}/devel/p5-Return-Value \
		${SITE_PERL}/UNIVERSAL/require.pm:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		p5-Net>0:${PORTSDIR}/net/p5-Net
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN3=	Email::Send.3 \
	Email::Send::NNTP.3 \
	Email::Send::Qmail.3 \
	Email::Send::SMTP.3 \
	Email::Send::Sendmail.3 \
	Email::Send::Test.3

.include <bsd.port.mk>
