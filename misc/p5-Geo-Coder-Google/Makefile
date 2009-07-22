# New ports collection makefile for:	Geo-Coder-Google
# Date created:				2008-11-06
# Whom:					Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Geo-Coder-Google
PORTVERSION=	0.05
CATEGORIES=	misc perl5 geography
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	Google Maps Geocoding API

RUN_DEPENDS=	p5-YAML-Syck>=0.1:${PORTSDIR}/textproc/p5-YAML-Syck \
		p5-libwww>=5.5:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Geo::Coder::Google.3

# The coordinates can be updated by anyone. It might change again in the future.
post-patch:
	@${REINPLACE_CMD} -e 's/-122.397323/-122.397711/' ${WRKSRC}/t/01_live.t

.include <bsd.port.mk>
