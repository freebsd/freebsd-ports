# New ports collection makefile for:	Math-GMP
# Date created:				Wed Jan  3 11:09:25 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Math-GMP
PORTVERSION=	2.06
PORTREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module that provides an interface to the GMP library

LIB_DEPENDS=	gmp.10:${PORTSDIR}/math/gmp

CONFIGURE_ARGS=	INC=-I${LOCALBASE}/include LIBS="-L${LOCALBASE}/lib -lgmp"
PERL_CONFIGURE=	yes

MAN3=		Math::GMP.3

.include <bsd.port.mk>
