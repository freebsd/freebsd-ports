# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-Singleton
PORTVERSION=	0.1
PORTEPOCH=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MRAMBERG
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Singleton accessors to context

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
