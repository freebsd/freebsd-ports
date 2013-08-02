# Changes: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-ConfigLoader
PORTVERSION=	0.32
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BOBTFISH
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Load config files of various types

RUN_DEPENDS=	p5-Catalyst-Runtime>=5.7008:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Data-Visitor>=0.24:${PORTSDIR}/devel/p5-Data-Visitor \
		p5-Config-Any>=0.20:${PORTSDIR}/devel/p5-Config-Any \
		p5-MRO-Compat>=0.09:${PORTSDIR}/devel/p5-MRO-Compat
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Catalyst::Plugin::ConfigLoader.3 \
	Catalyst::Plugin::ConfigLoader::Manual.3

.include <bsd.port.mk>
