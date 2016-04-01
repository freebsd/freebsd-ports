# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	PPIx-Utilities
PORTVERSION=	1.001000
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ELLIOTJS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extensions to PPI

RUN_DEPENDS=	p5-Exception-Class>=1.23:devel/p5-Exception-Class \
		p5-PPI>=1.208:textproc/p5-PPI \
		p5-Readonly>=1.03:devel/p5-Readonly \
		p5-Task-Weaken>=0:devel/p5-Task-Weaken
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
