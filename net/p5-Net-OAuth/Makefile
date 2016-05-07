# Created by: ijliao
# $FreeBSD$

PORTNAME=	Net-OAuth
PORTVERSION=	0.28
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Implementation of the OAuth protocol

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Accessor>=0.31:devel/p5-Class-Accessor \
		p5-Class-Data-Inheritable>=0.06:devel/p5-Class-Data-Inheritable \
		p5-Digest-HMAC>=1.01:security/p5-Digest-HMAC \
		p5-URI>=1.35:net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Warn>=0.21:devel/p5-Test-Warn

USE_PERL5=	modbuild
USES=		perl5

.include <bsd.port.mk>
