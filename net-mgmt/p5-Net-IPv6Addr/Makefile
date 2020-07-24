# Created by: JJ Behrens <jj@nttmcl.com>
# $FreeBSD$

PORTNAME=	Net-IPv6Addr
PORTVERSION=	1.01
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for manipulating IPv6 addresses

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Math-Base85>=0.2:math/p5-Math-Base85 \
		p5-Math-BigInt>=1.999813:math/p5-Math-BigInt \
		p5-Net-IPv4Addr>=0.10:net-mgmt/p5-Net-IPv4Addr

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
