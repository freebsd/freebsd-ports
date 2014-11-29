# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Text-Prefix-XS
PORTVERSION=	0.15
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast prefix searching

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Digest-SHA1>=1:${PORTSDIR}/security/p5-Digest-SHA1
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Deep>=0.108:${PORTSDIR}/devel/p5-Test-Deep

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
