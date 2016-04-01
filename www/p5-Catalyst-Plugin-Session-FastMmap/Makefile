# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-Session-FastMmap
PORTVERSION=	0.13
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BOBTFISH
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	FastMmap sessions for Catalyst

BUILD_DEPENDS=	p5-Cache-FastMmap>0:devel/p5-Cache-FastMmap \
		p5-Catalyst-Runtime>2.99:www/p5-Catalyst-Runtime \
		p5-Class-Accessor>0:devel/p5-Class-Accessor \
		p5-Class-Data-Inheritable>0:devel/p5-Class-Data-Inheritable \
		p5-MRO-Compat>0:devel/p5-MRO-Compat \
		p5-URI-Find>0:textproc/p5-URI-Find \
		p5-URI>0:net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

regression-test: build
	cd ${WRKSRC}/ && ${MAKE} test

.include <bsd.port.mk>
