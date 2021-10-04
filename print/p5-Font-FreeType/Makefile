PORTNAME=	Font-FreeType
PORTVERSION=	0.07
CATEGORIES=	print perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to read font files and render glyphs using FreeType2

LICENSE=	ARTPERL10

BUILD_DEPENDS=	p5-Devel-CheckLib>=0:devel/p5-Devel-CheckLib \
		p5-File-Which>=0:sysutils/p5-File-Which
LIB_DEPENDS=	libfreetype.so:print/freetype2
TEST_DEPENDS=	p5-Test-Warnings>=0:devel/p5-Test-Warnings

USES=		perl5 pkgconfig
USE_PERL5=	configure

BINARY_ALIAS=	freetype-config=true

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Font/FreeType/FreeType.so

.include <bsd.port.mk>
