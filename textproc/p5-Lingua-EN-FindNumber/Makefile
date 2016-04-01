# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Lingua-EN-FindNumber
PORTVERSION=	1.32
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Locate (written) numbers in English text

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Lingua-EN-Words2Nums>=0:textproc/p5-Lingua-EN-Words2Nums
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Pod>=1:devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=1:devel/p5-Test-Pod-Coverage

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
