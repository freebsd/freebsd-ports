# Created by: Zane C. Bowers-Hadley <vvelox@vvelox.net>
# $FreeBSD$

PORTNAME=	Net-Connection-lsof
PORTVERSION=	0.2.0
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Creates Net::Connection objects using lsof

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Net-Connection>=0.2.0:net/p5-Net-Connection \
		p5-Proc-ProcessTable>=0.59:devel/p5-Proc-ProcessTable

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
