# Created by: lbr@FreeBSD.org
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-ConfigLoader-Environment
PORTVERSION=	0.07
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Configure your application with environment variables

RUN_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-JSON-Any>=0:${PORTSDIR}/converters/p5-JSON-Any \
		p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Catalyst::Plugin::ConfigLoader::Environment.3

NO_STAGE=	yes
.include <bsd.port.mk>
