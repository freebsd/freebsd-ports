# Created by: Yi-Hsuan Hsin <mhsin@mhsin.org>
# $FreeBSD$

PORTNAME=	WWW-Plurk
PORTVERSION=	0.02
PORTREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	mhsin@mhsin.org
COMMENT=	Unofficial plurk.com API

RUN_DEPENDS=	p5-DateTime-Format-Mail>=0:devel/p5-DateTime-Format-Mail \
		p5-HTML-Tiny>=0:textproc/p5-HTML-Tiny \
		p5-JSON>=2.00:converters/p5-JSON \
		p5-Math-Base36>=0:math/p5-Math-Base36 \
		p5-libwww>=0:www/p5-libwww
BUILD_DEPENDS:=	${RUN_DEPENDS}
BUILD_DEPENDS+=	p5-Test-Deep>=0:devel/p5-Test-Deep

USES=		perl5
USE_PERL5=	configure

post-patch:
	${FIND} ${WRKSRC} -name "*.orig" -delete

.include <bsd.port.mk>
