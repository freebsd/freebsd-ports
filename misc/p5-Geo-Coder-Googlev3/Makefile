# New ports collection makefile for:	p5-Geo-Coder-Googlev3
# Date created:		2011-10-13
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Geo-Coder-Googlev3
PORTVERSION=	0.10
CATEGORIES=	misc geography perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Maps v3 Geocoding API

BUILD_DEPENDS=	p5-JSON-XS>=0:${PORTSDIR}/converters/p5-JSON-XS \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	p5-JSON-XS>=0:${PORTSDIR}/converters/p5-JSON-XS \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN3=		Geo::Coder::Googlev3.3

.include <bsd.port.mk>
