# Created by: Oleg Mamontov <oleg@mamontov.net>
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-SmartURI
PORTVERSION=	0.041
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	oleg@mamontov.net
COMMENT=	Configurable URIs for Catalyst

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Catalyst-Runtime>=0:${PORTSDIR}/www/p5-Catalyst-Runtime	\
		p5-Class-C3-Componentised>=0:${PORTSDIR}/devel/p5-Class-C3-Componentised	\
		p5-Class-Load>=0:${PORTSDIR}/devel/p5-Class-Load		\
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose 				\
		p5-URI-SmartURI>=0:${PORTSDIR}/net/p5-URI-SmartURI
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
