# New ports collection makefile for:	p5-HTTP-MobileAgent
# Date created:		27 February 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	HTTP-MobileAgent
PORTVERSION=	0.33
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	An HTTP mobile user agent string parser for Perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-libwww>=1.43:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS=	${RUN_DEPENDS}

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
