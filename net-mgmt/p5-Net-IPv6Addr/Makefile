# Created by: JJ Behrens <jj@nttmcl.com>

PORTNAME=	Net-IPv6Addr
PORTVERSION=	1.02
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for manipulating IPv6 addresses

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 503000
BUILD_DEPENDS+=	p5-Math-BigInt>=1.999813:math/p5-Math-BigInt
RUN_DEPENDS+=	p5-Math-BigInt>=1.999813:math/p5-Math-BigInt
.endif

.include <bsd.port.post.mk>
