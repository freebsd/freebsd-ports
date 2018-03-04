# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Geo-WebService-Elevation-USGS
PORTVERSION=	0.107
CATEGORIES=	science perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:WYANT
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for elevation queries against USGS web services

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-JSON>=0:converters/p5-JSON \
		p5-libwww>=0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

PORTSCOUT=	limit:^[0-9\.]*$$

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
