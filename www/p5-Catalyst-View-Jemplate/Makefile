# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-View-Jemplate
PORTVERSION=	0.06
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Jemplate files server

RUN_DEPENDS=	p5-File-Find-Rule>0:devel/p5-File-Find-Rule \
		p5-Catalyst-Runtime>=5.50:www/p5-Catalyst-Runtime \
		p5-Jemplate>=0.19:www/p5-Jemplate
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
