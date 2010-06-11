# New ports collection makefile for:	Math-MPFR
# Date created:				31 Jan 2009
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Math-MPFR
PORTVERSION=	3.0
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A perl interface to MPFR Library

LIB_DEPENDS=	mpfr.3:${PORTSDIR}/math/mpfr

PERL_CONFIGURE=	yes
MAKE_ENV=	INC="-I${LOCALBASE}/include"

MAN3=		Math::MPFR.3

.include <bsd.port.mk>
