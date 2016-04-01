# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Geo-Coordinates-Converter
PORTVERSION=	0.13
PORTREVISION=	1
CATEGORIES=	science geography perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple converter of geo coordinates

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Accessor-Lite>=0.05:devel/p5-Class-Accessor-Lite \
		p5-String-CamelCase>0:textproc/p5-String-CamelCase \
		p5-YAML>0:textproc/p5-YAML
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Base>0:devel/p5-Test-Base

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
