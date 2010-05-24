# New ports collection makefile for:	p5-Net-Twitter-Lite
# Date created:				Aug  2, 2009
# Whom:					Masafumi NAKANE <max@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Twitter-Lite
PORTVERSION=	0.10000
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	max@FreeBSD.org
COMMENT=	A perl interface to the Twitter API

BUILD_DEPENDS=	p5-JSON-Any>=1.21:${PORTSDIR}/converters/p5-JSON-Any \
		${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/URI/Escape.pm:${PORTSDIR}/net/p5-URI \
		p5-Net-OAuth>=0.25:${PORTSDIR}/net/p5-Net-OAuth
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
MAN3=		Net::Twitter::Lite.3 Net::Twitter::Lite::Error.3

.include <bsd.port.mk>
