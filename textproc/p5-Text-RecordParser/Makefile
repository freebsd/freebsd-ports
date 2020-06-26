# $FreeBSD$

PORTNAME=	Text-RecordParser
PORTVERSION=	1.6.5
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Read record-oriented files

LICENSE=	GPLv2

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-IO-Stringy>=0:devel/p5-IO-Stringy \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Readonly>=0:devel/p5-Readonly \
		p5-Text-Autoformat>=0:textproc/p5-Text-Autoformat \
		p5-Text-TabularDisplay>=1.22:textproc/p5-Text-TabularDisplay
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
