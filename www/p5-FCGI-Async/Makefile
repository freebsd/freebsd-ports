# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	FCGI-Async
PORTVERSION=	0.22
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Module to allow use of FastCGI asynchronously

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-IO-Async>=0:${PORTSDIR}/devel/p5-IO-Async \
		p5-Net-Async-FastCGI>=0:${PORTSDIR}/www/p5-Net-Async-FastCGI \
  		p5-Net-FastCGI>=0:${PORTSDIR}/www/p5-Net-FastCGI
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Identity>=0:${PORTSDIR}/devel/p5-Test-Identity \
		p5-Test-HexString>=0:${PORTSDIR}/devel/p5-Test-HexString \
		p5-Test-Refcount>0:${PORTSDIR}/devel/p5-Test-Refcount

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
