# New ports collection makefile for:	mail/p5-Email-Find
# Date created:				28 December 2000
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	Email-Find
PORTVERSION=	0.09
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Email
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Find RFC 822 email addresses in plain text

BUILD_DEPENDS=	${SITE_PERL}/Email/Valid.pm:${PORTSDIR}/mail/p5-Email-Valid
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Email::Find.3 Email::Find::addrspec.3

.include <bsd.port.mk>
