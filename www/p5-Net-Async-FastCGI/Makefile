# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-Async-FastCGI
PORTVERSION=	0.25
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to use FastCGI with IO::Async

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-IO-Async>=0:${PORTSDIR}/devel/p5-IO-Async \
		p5-Net-FastCGI>=0:${PORTSDIR}/www/p5-Net-FastCGI
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-HexString>=0:${PORTSDIR}/devel/p5-Test-HexString \
		p5-Test-Refcount>0:${PORTSDIR}/devel/p5-Test-Refcount \
		p5-Test-Identity>=0:${PORTSDIR}/devel/p5-Test-Identity

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
