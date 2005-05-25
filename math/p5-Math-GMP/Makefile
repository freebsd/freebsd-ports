# New ports collection makefile for:	Math-GMP
# Date created:				Wed Jan  3 11:09:25 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Math-GMP
PORTVERSION=	2.04
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Math
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Perl module that provides an interface to the GMP library

LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4

PERL_CONFIGURE=	yes

MAN3=		Math::GMP.3

post-patch:
	@${PERL} -pi -e "s!-lgmp!-L${LOCALBASE}/lib $$&!;" \
		     -e "if (/LIBS/) { print qq!'INC' => '-I${LOCALBASE}/include',!; }" \
		${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
