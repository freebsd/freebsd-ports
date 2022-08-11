PORTNAME=	Mail-RBL
PORTVERSION=	1.10
PORTREVISION=	2
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to access RBL-style host verification services

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Net-DNS>=0:dns/p5-Net-DNS \
		p5-NetAddr-IP>0:net-mgmt/p5-NetAddr-IP

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
