# New ports collection makefile for:	Chemistry-Mol
# Date created:				11 May, 2009
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Chemistry-Mol
PORTVERSION=	0.37
CATEGORIES=	science perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wenheping@gmail.com
COMMENT=	Perl toolkit to describe molecules

BUILD_DEPENDS=	p5-Math-VectorReal>=1.02:${PORTSDIR}/math/p5-Math-VectorReal
RUN_DEPENDS=	p5-Math-VectorReal>=1.02:${PORTSDIR}/math/p5-Math-VectorReal

PERL_CONFIGURE=	yes

MAN3=	Chemistry::Atom.3 Chemistry::Bond.3 \
	Chemistry::Obj.3 Chemistry::File.3 \
	Chemistry::Tutorial.3 Chemistry::File::Dumper.3 \
	Chemistry::Mol.3 Chemistry::File::Formula.3

.include <bsd.port.mk>
