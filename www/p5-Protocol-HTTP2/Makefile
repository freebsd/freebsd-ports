# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Protocol-HTTP2
PORTVERSION=	1.00
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CRUX
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTTP/2 protocol implementation

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-AnyEvent>=0:${PORTSDIR}/devel/p5-AnyEvent \
		p5-Net-SSLeay>=1.45:${PORTSDIR}/security/p5-Net-SSLeay
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-TCP>=0:${PORTSDIR}/devel/p5-Test-TCP

USE_PERL5=	modbuildtiny
USES=		perl5

.include <bsd.port.mk>
