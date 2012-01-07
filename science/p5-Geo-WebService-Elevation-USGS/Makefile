# New ports collection makefile for:	p5-Geo-WebService-Elevation-USGS
# Date created:				15 Jan, 2010
# Whom:					Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Geo-WebService-Elevation-USGS
PORTVERSION=	0.010
CATEGORIES=	science perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:WYANT
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for elevation queries against USGS web services

BUILD_DEPENDS=	p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN3=		Geo::WebService::Elevation::USGS.3

.include <bsd.port.mk>
