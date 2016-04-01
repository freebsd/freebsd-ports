# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Geo-Coder-OpenCage
PORTVERSION=	0.05
PORTREVISION=	1
CATEGORIES=	misc geography perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Geocode addresses with the OpenCage Geocoder API

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-JSON>=2.53:converters/p5-JSON \
		p5-List-MoreUtils>=0.33:lang/p5-List-MoreUtils \
		p5-URI>=1.60:net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0.32:devel/p5-Test-Exception

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502000
BUILD_DEPENDS+=	p5-HTTP-Tiny>=0.028:www/p5-HTTP-Tiny \
		p5-Pod-Perldoc>=3.21:textproc/p5-Pod-Perldoc
RUN_DEPENDS+=	p5-HTTP-Tiny>=0.028:www/p5-HTTP-Tiny \
		p5-Pod-Perldoc>=3.21:textproc/p5-Pod-Perldoc
.endif

.include <bsd.port.post.mk>
