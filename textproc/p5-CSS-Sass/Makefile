# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	CSS-Sass
PORTVERSION=	3.6.2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Compile .scss and .sass files using LibSass

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-ExtUtils-CppGuess>=0.14:devel/p5-ExtUtils-CppGuess \
		${RUN_DEPENDS}
RUN_DEPENDS=	p5-Encode-Locale>=0.01:converters/p5-Encode-Locale \
		p5-Filesys-Notify-KQueue>=0.01:devel/p5-Filesys-Notify-KQueue \
		p5-Filesys-Notify-Simple>=0.01:devel/p5-Filesys-Notify-Simple
TEST_DEPENDS=	p5-File-chdir>=0.01:devel/p5-File-chdir \
		p5-Test-Differences>=0.01:devel/p5-Test-Differences \
		p5-YAML-LibYAML>=0.01:textproc/p5-YAML-LibYAML

USES=		compiler:c++11-lang gmake perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/CSS/Sass/Sass.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/CSS/Sass/libsass.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/CSS/Sass/plugins/digest/digest.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/CSS/Sass/plugins/glob/glob.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/CSS/Sass/plugins/img-size/img-size.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/CSS/Sass/plugins/math/math.so

.include <bsd.port.mk>
