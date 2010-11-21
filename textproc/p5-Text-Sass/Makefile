# New ports collection makefile for:	Text::Sass
# Date created:		07 Apr 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Text-Sass
PORTVERSION=	0.9
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl implementation of http://sass-lang.com/

RUN_DEPENDS=	\
	p5-Readonly>=1.03:${PORTSDIR}/devel/p5-Readonly
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	Text::Sass.3 \
	Text::Sass::Expr.3 \
	Text::Sass::Functions.3

.include <bsd.port.mk>
