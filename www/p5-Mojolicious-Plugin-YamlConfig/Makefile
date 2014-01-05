# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Mojolicious-Plugin-YamlConfig
PORTVERSION=	0.1.5
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	YAML Configuration Plugin

BUILD_DEPENDS=	p5-Mojolicious>=1.80:${PORTSDIR}/www/p5-Mojolicious \
		p5-YAML-Tiny>=1.51:${PORTSDIR}/textproc/p5-YAML-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
