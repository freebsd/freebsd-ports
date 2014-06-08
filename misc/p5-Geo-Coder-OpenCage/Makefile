# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Geo-Coder-OpenCage
PORTVERSION=	0.02
CATEGORIES=	misc geography perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:KAORU
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Geocode addresses with the OpenCage Geocoder API

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-JSON>=2.53:${PORTSDIR}/converters/p5-JSON \
		p5-URI>=1.60:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0.32:${PORTSDIR}/devel/p5-Test-Exception

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501600
BUILD_DEPENDS+=	p5-Carp>=1.26:${PORTSDIR}/devel/p5-Carp
RUN_DEPENDS+=	p5-Carp>=1.26:${PORTSDIR}/devel/p5-Carp
.endif

.if ${PERL_LEVEL} < 502000
BUILD_DEPENDS+=	p5-HTTP-Tiny>=0.028:${PORTSDIR}/www/p5-HTTP-Tiny
RUN_DEPENDS+=	p5-HTTP-Tiny>=0.028:${PORTSDIR}/www/p5-HTTP-Tiny
.endif

.include <bsd.port.post.mk>
