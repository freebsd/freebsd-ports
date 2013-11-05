# $FreeBSD$

PORTNAME=	SOAP-Transport-TCP
PORTVERSION=	0.717
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	TCP Transport Support for SOAP::Lite

RUN_DEPENDS=	p5-SOAP-Lite>=0.714:${PORTSDIR}/net/p5-SOAP-Lite
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
