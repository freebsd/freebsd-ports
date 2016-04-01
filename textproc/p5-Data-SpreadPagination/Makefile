# Created by: Sergei Vyshenski <svysh.fbsd@gmail.com>
# $FreeBSD$

PORTNAME=	Data-SpreadPagination
PORTVERSION=	0.1.2
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Page numbering and spread pagination

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Data-Page>=0:databases/p5-Data-Page \
		p5-Math-Round>=0:math/p5-Math-Round
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Pod>=0:devel/p5-Test-Pod

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
