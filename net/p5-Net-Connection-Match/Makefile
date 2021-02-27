# Created by: Zane C. Bowers-Hadley <vvelox@vvelox.net>
# $FreeBSD$

PORTNAME=	Net-Connection-Match
PORTVERSION=	0.5.0
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Runs a stack of checks to match Net::Connection objects

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Net-DNS>=1.20:dns/p5-Net-DNS \
		p5-Net-CIDR>=-0.20:net-mgmt/p5-Net-CIDR \
		p5-Net-Connection>=0.0.1:net/p5-Net-Connection \
		p5-Proc-ProcessTable>=0.59:devel/p5-Proc-ProcessTable \
		p5-Error-Helper>=1.0.0:devel/p5-Error-Helper

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
