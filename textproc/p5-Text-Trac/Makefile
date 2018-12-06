# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Text-Trac
PORTVERSION=	0.20
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for formatting text with Trac Wiki Style

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Class-Data-Inheritable>=0:devel/p5-Class-Data-Inheritable \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Tie-IxHash>=0:devel/p5-Tie-IxHash \
		p5-Path-Tiny>=0:devel/p5-Path-Tiny \
		p5-UNIVERSAL-require>=0:devel/p5-UNIVERSAL-require
TEST_DEPENDS=	p5-Test-Base>=0:devel/p5-Test-Base

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
