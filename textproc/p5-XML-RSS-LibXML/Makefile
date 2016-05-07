# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	XML-RSS-LibXML
PORTVERSION=	0.3105
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	XML::RSS with XML::LibXML

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-DateTime-Format-Mail>=0:devel/p5-DateTime-Format-Mail \
		p5-DateTime-Format-W3CDTF>=0:devel/p5-DateTime-Format-W3CDTF \
		p5-UNIVERSAL-require>=0:devel/p5-UNIVERSAL-require \
		p5-XML-LibXML>=1.66:textproc/p5-XML-LibXML
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Differences>=0:devel/p5-Test-Differences \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Warn>=0:devel/p5-Test-Warn

OPTIONS_DEFINE=	EXAMPLES

USES=		perl5 shebangfix
SHEBANG_FILES=	tools/benchmark.pl
perl_OLD_CMD=	perl
USE_PERL5=	modbuild
NO_ARCH=	yes

PORTEXAMPLES=	benchmark.pl

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/tools/benchmark.pl ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
