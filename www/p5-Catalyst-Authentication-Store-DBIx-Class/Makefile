# Created by: Oleg Mamontov <oleg@mamontov.net>
# $FreeBSD$

PORTNAME=	Catalyst-Authentication-Store-DBIx-Class
PORTVERSION=	0.1506
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	oleg@mamontov.net
COMMENT=	Storage class for Catalyst Authentication using DBIx::Class

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Catalyst-Model-DBIC-Schema>=0.18:www/p5-Catalyst-Model-DBIC-Schema \
		p5-Catalyst-Plugin-Authentication>=0.10008:www/p5-Catalyst-Plugin-Authentication \
		p5-Catalyst-Runtime>=5.8:www/p5-Catalyst-Runtime \
		p5-DBIx-Class>=0.08:databases/p5-DBIx-Class \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Moose>=0:devel/p5-Moose \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

PATCH_STRIP=	-p1

.include <bsd.port.mk>
