# New ports collection makefile for:	p5-HTTP-MobileAgent
# Date created:		27 February 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	HTTP-MobileAgent
PORTVERSION=	0.22
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTTP
PKGNAMEPREFIX=	p5-

MAINTAINER=	knu@FreeBSD.org
COMMENT=	An HTTP mobile user agent string parser for Perl

BUILD_DEPENDS=	${SITE_PERL}/HTTP/Headers.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		HTTP::MobileAgent.3 \
		HTTP::MobileAgent::AirHPhone.3 \
		HTTP::MobileAgent::Display.3 \
		HTTP::MobileAgent::DoCoMo.3 \
		HTTP::MobileAgent::EZweb.3 \
		HTTP::MobileAgent::JPhone.3 \
		HTTP::MobileAgent::NonMobile.3 \
		HTTP::MobileAgent::Vodafone.3

.include <bsd.port.mk>
