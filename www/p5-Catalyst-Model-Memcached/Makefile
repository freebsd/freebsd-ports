# Created by: Denis Pokataev <catone@cpan.org>
# $FreeBSD$

PORTNAME=	Catalyst-Model-Memcached
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Wrapper for memcached imitating Catalyst models

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Cache-Memcached-Fast>=0.17:databases/p5-Cache-Memcached-Fast \
		p5-Catalyst-Runtime>=5.8:www/p5-Catalyst-Runtime

USES=		perl5 tar:tgz
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
