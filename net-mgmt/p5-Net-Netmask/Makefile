# Created by: Wei-chun Chao
# $FreeBSD$

PORTNAME=	Net-Netmask
PORTVERSION=	1.9104
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to parse, manipulate, and lookup IP network blocks

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	p5-Test-UseAllModules>=0:devel/p5-Test-UseAllModules \
		p5-Test2-Suite>=0:devel/p5-Test2-Suite

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502705
BUILD_DEPENDS+=	p5-Math-BigInt>=1.999811:math/p5-Math-BigInt
RUN_DEPENDS+=	p5-Math-BigInt>=1.999811:math/p5-Math-BigInt
.endif

.include <bsd.port.post.mk>
