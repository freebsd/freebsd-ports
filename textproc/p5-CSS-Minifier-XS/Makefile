# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	CSS-Minifier-XS
PORTVERSION=	0.09
PORTREVISION=	2
CATEGORIES=	textproc www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	XS based CSS minifier

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-CSS-Minifier>=0:textproc/p5-CSS-Minifier \
		p5-Test-Pod>=1:devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=1:devel/p5-Test-Pod-Coverage

USE_PERL5=	configure
USES=		perl5

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/CSS/Minifier/XS/XS.so

.include <bsd.port.mk>
