# New ports collection makefile for:	p5-Math-Pari
# Date created:				Tue Sep 11 02:08:49 PDT 2001
# Whom:	      				Michael Haro <mharo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Math-Pari
PORTVERSION=	2.01080604
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	PARI - numerical/scientific/number-theoretic calculations

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/math/pari:configure
LIB_DEPENDS=	pari:${PORTSDIR}/math/pari

PERL_CONFIGURE=	yes

CONFIGURE_ARGS=	parilib="-L${LOCALBASE}/lib -lpari" \
		paridir=`${MAKE} -C ${PORTSDIR}/math/pari -V WRKSRC`

MAN3=		Math::Pari.3 Math::libPARI.3 Math::PariInit.3

post-patch:
	${REINPLACE_CMD} -e 's/2001004/2003000/' ${WRKSRC}/Makefile.PL

post-clean:
	${MAKE} -C ${PORTSDIR}/math/pari -DBATCH clean

.include <bsd.port.mk>
