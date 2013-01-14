# $FreeBSD$

PORTNAME=	Text-Sass
PORTVERSION=	0.97
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RPETTETT
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl implementation of http://sass-lang.com/

RUN_DEPENDS=	\
	p5-Readonly>=1.03:${PORTSDIR}/devel/p5-Readonly \
	p5-Convert-Color>0:${PORTSDIR}/graphics/p5-Convert-Color
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Try-Tiny>0:${PORTSDIR}/lang/p5-Try-Tiny

PERL_MODBUILD=	yes

MAN3=	Text::Sass.3 \
	Text::Sass::Expr.3 \
	Text::Sass::Functions.3

.include <bsd.port.mk>
