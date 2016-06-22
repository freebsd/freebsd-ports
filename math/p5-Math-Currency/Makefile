# Created by: will
# $FreeBSD$

PORTNAME=	Math-Currency
PORTVERSION=	0.49
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for exact currency math with formatting and rounding

BUILD_DEPENDS=	p5-Math-FixedPrecision>=0:math/p5-Math-FixedPrecision
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-More-UTF8>=0:devel/p5-Test-More-UTF8

USES=		perl5
USE_PERL5=	modbuild

OPTIONS_DEFINE=	DOCS

PORTDOCS=	Changes

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
