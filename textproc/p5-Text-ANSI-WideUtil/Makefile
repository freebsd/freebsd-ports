# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Text-ANSI-WideUtil
PORTVERSION=	0.230
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Routines for text containing ANSI color codes (wide-character functions only)

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Text-ANSI-Util>=0.19:textproc/p5-Text-ANSI-Util \
		p5-Text-WideChar-Util>=0.100:textproc/p5-Text-WideChar-Util
TEST_DEPENDS=	p5-Data-Dump>=0:devel/p5-Data-Dump

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
