# New ports collection makefile for:	HTTP::MobileAgent::Plugin::Charset
# Date created:		20 Feb 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTTP-MobileAgent-Plugin-Charset
PORTVERSION=	0.04
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to plugin Encode::JP::Mobile for HTTP::MobileAgent

RUN_DEPENDS=	\
	p5-HTTP-MobileAgent>=0.26:${PORTSDIR}/www/p5-HTTP-MobileAgent
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	HTTP::MobileAgent::Plugin::Charset.3

.include <bsd.port.mk>
