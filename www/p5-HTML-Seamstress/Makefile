# Created by: chinsan
# $FreeBSD$

PORTNAME=	HTML-Seamstress
PORTVERSION=	6.112830
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	HTML::Tree subclass for HTML templating via tree rewriting

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-HTML-Element-Library>=0:www/p5-HTML-Element-Library \
		p5-HTML-Element-Replacer>=0:www/p5-HTML-Element-Replacer \
		p5-HTML-Tree>=0:www/p5-HTML-Tree \
		p5-Set-Array>=0:devel/p5-Set-Array
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Class-Prototyped>=0:devel/p5-Class-Prototyped

NO_ARCH=	yes
USES=		perl5 shebangfix
USE_PERL5=	configure

SHEBANG_FILES=	lib/HTML/Seamstress/tt.pl

.include <bsd.port.mk>
