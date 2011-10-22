# New ports collection makefile for:	Geo-Coder-Google
# Date created:				2008-11-06
# Whom:					Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Geo-Coder-Google
PORTVERSION=	0.07
CATEGORIES=	misc perl5 geography
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	Google Maps Geocoding API

BUILD_DEPENDS=	p5-JSON>=2.27:${PORTSDIR}/converters/p5-JSON \
		p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-libwww>=5.5:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Geo::Coder::Google.3 \
		Geo::Coder::Google::V2.3 \
		Geo::Coder::Google::V3.3

.include <bsd.port.mk>
