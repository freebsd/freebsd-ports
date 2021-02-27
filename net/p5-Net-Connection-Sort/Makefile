# Created by: Zane C. Bowers-Hadley <vvelox@vvelox.net>
# $FreeBSD$

PORTNAME=	Net-Connection-Sort
PORTVERSION=	0.0.1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Sorts array of Net::Connection objects

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Net-IP>=1.26:net-mgmt/p5-Net-IP \
		p5-Net-Connection>=0.0.1:net/p5-Net-Connection

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
