# New ports collection makefile for:	Math-GMP
# Date created:				Wed Jan  3 11:09:25 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Math-GMP
PORTVERSION=	1.07
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Math
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
LIB_DEPENDS=	gmp:${PORTSDIR}/math/libgmp4
CONFIGURE_ENV+=	GMP=${LOCALBASE}
.else
CONFIGURE_ENV+= GMP=/usr
.endif

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Math::GMP.3

.include <bsd.port.post.mk>
