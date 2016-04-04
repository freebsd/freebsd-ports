# $FreeBSD$

PORTNAME=	Text-RecordParser
PORTVERSION=	1.6.3
PORTREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Read record-oriented files

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-IO-stringy>=0:devel/p5-IO-stringy \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Pod-Markdown>=0:textproc/p5-Pod-Markdown \
		p5-Pod-Readme>=0:textproc/p5-Pod-Readme \
		p5-Readonly>=0:devel/p5-Readonly \
		p5-Text-Autoformat>=0:textproc/p5-Text-Autoformat \
		p5-Text-TabularDisplay>=0:textproc/p5-Text-TabularDisplay
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	modbuild

post-extract:
		# workaround for https://rt.cpan.org/Public/Bug/Display.html?id=87855
		${CHMOD} +w ${WRKSRC}/README.md

.include <bsd.port.mk>
