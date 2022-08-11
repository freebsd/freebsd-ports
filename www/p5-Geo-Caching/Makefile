PORTNAME=	Geo-Caching
PORTVERSION=	0.11
PORTREVISION=	2
CATEGORIES=	www perl5 geography
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Object interface for querying Geocaching.com website

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Geo-Cache>=0:misc/p5-Geo-Cache \
		p5-WWW-Mechanize>=0:www/p5-WWW-Mechanize \
		p5-Geo-Gpx>=0:graphics/p5-Geo-Gpx

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
