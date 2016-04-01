# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Math-Random-MT-Auto
PORTVERSION=	6.22
PORTREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Auto-seeded Mersenne Twister PRNGs

BUILD_DEPENDS=	p5-Exception-Class>=1.32:devel/p5-Exception-Class \
		p5-Object-InsideOut>=3.88:devel/p5-Object-InsideOut
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-libwww>=0:www/p5-libwww

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
