# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	POE-Component-SSLify
PORTVERSION=	1.012
CATEGORIES=	security perl5
MASTER_SITES=	CPAN/${PORTNAME:C/-.*//}/APOCAL
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Integrate SSL into POE

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Net-SSLeay>=1.36:security/p5-Net-SSLeay \
		p5-POE>=1.267:devel/p5-POE \
		p5-Task-Weaken>=1.03:devel/p5-Task-Weaken
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-FailWarnings>=0:devel/p5-Test-FailWarnings

USES=		perl5
USE_PERL5=	modbuildtiny

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502000
TEST_DEPENDS+=	p5-Test-Simple>=1.001002:devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
