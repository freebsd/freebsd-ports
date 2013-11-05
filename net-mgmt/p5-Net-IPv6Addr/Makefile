# Created by: JJ Behrens <jj@nttmcl.com>
# $FreeBSD$

PORTNAME=	Net-IPv6Addr
PORTVERSION=	0.2
CATEGORIES=	net-mgmt perl5 ipv6
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl extension for manipulating IPv6 addresses

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Net-IPv4Addr>=0:${PORTSDIR}/net-mgmt/p5-Net-IPv4Addr \
		p5-Math-Base85>=0:${PORTSDIR}/math/p5-Math-Base85
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
