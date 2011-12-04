# New ports collection makefile for:	Fliggy
# Date created:		04 Dec 2011
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Fliggy
PORTVERSION=	0.009003
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/V/VT/VTI
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for Fliggy: Twiggy with inlined flash policy server

RUN_DEPENDS=	\
	p5-Twiggy>0:${PORTSDIR}/www/p5-Twiggy
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Fliggy.3 \
	Fliggy::Server.3 \
	Plack::Handler::Fliggy.3

.include <bsd.port.mk>
