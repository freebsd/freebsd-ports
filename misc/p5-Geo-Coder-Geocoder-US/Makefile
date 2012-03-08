# New ports collection makefile for:	p5-Geo-Coder-Geocoder-US
# Date created:		2011-12-06
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Geo-Coder-Geocoder-US
PORTVERSION=	0.003
CATEGORIES=	misc geography perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:WYANT
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Geocode a location using http://geocoder.us/

BUILD_DEPENDS=	p5-Text-CSV>=0:${PORTSDIR}/textproc/p5-Text-CSV \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	p5-Text-CSV>=0:${PORTSDIR}/textproc/p5-Text-CSV \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN3=		Geo::Coder::Geocoder::US.3

.include <bsd.port.mk>
