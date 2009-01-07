# New ports collection makefile for:	p5-Data-Validate-Email
# Date created:		2009-01-07
# Whom:			Murilo Opsfelder <mopsfelder@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Data-Validate-Email
PORTVERSION=	0.04
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	mopsfelder@gmail.com
COMMENT=	A common email validation written in Perl

RUN_DEPENDS=	${SITE_PERL}/Data/Validate/Domain.pm:${PORTSDIR}/dns/p5-Data-Validate-Domain \
		${SITE_PERL}/Email/Address.pm:${PORTSDIR}/mail/p5-Email-Address \
		${SITE_PERL}/Net/Domain/TLD.pm:${PORTSDIR}/dns/p5-Net-Domain-TLD

PERL_CONFIGURE=	yes

MAN3=		Data::Validate::Email.3

.include <bsd.port.mk>
