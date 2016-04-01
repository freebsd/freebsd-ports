# $FreeBSD$

PORTNAME=	Template-Stash-AutoEscape
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to escape automatically in Template-Toolkit

RUN_DEPENDS=	\
	p5-Class-Data-Inheritable>0:devel/p5-Class-Data-Inheritable \
	p5-Template-Toolkit>0:www/p5-Template-Toolkit \
	p5-UNIVERSAL-require>0:devel/p5-UNIVERSAL-require
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-URI>=0:net/p5-URI

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
