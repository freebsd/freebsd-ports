# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Text-MultiMarkdown
PORTVERSION=	1.000035
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Convert MultiMarkdown syntax to (X)HTML

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	p5-Text-Markdown>=1.0.26:textproc/p5-Text-Markdown
RUN_DEPENDS:=	p5-HTML-Parser>0:www/p5-HTML-Parser \
		${BUILD_DEPENDS}
TEST_DEPENDS=	p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
