# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-Static
PORTVERSION=	0.11
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BOBTFISH
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Serve static files with Catalyst

BUILD_DEPENDS=	p5-Catalyst-Runtime>=2.99:www/p5-Catalyst-Runtime \
		p5-Class-Data-Inheritable>=0:devel/p5-Class-Data-Inheritable \
		p5-File-MimeInfo>=0.11:devel/p5-File-MimeInfo \
		p5-File-Slurp>0:devel/p5-File-Slurp \
		p5-MRO-Compat>0:devel/p5-MRO-Compat
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

regression-test: build
	cd ${WRKSRC}/ && ${MAKE} test

.include <bsd.port.mk>
