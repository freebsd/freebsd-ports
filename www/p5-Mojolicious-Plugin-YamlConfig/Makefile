# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Mojolicious-Plugin-YamlConfig
PORTVERSION=	0.2.1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	YAML Configuration Plugin

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Mojolicious>=5.54:www/p5-Mojolicious \
		p5-YAML-Tiny>=1.60:textproc/p5-YAML-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Compile>=0:devel/p5-Test-Compile

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
