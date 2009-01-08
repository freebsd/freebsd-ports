# ex:ts=8
# Ports collection makefile for:	HTML::GoogleMaps
# Date created:				2008-11-06
# Whom:					Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTML-GoogleMaps
PORTVERSION=	10
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	A simple wrapper around the Google Maps API

RUN_DEPENDS=	p5-Geo-Coder-Google>=0.02:${PORTSDIR}/misc/p5-Geo-Coder-Google
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		HTML::GoogleMaps.3

post-extract:
	@${FIND} ${WRKSRC} -name ".*.pm" -delete

post-patch:
	@${FIND} ${WRKSRC} -name "*.orig" -delete

.include <bsd.port.mk>
