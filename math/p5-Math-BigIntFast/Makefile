# New ports collection makefile for:	Math-BigIntFast
# Date created:				Wed Jan  3 11:30:25 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Math-BigIntFast
PORTVERSION=	6.0
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Math
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Perl module wrapper for Bit::Vector to provide big integer math

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Bit/Vector.pm:${PORTSDIR}/math/p5-Bit-Vector
RUN_DEPENDS=	${BUILD_DEPENDS}

SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Math::BigIntFast.3

.include <bsd.port.mk>
