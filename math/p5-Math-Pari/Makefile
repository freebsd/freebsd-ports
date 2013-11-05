# Created by: Michael Haro <mharo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Math-Pari
PORTVERSION=	2.01080605
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	PARI - numerical/scientific/number-theoretic calculations

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/math/pari:configure
LIB_DEPENDS=	libpari.so:${PORTSDIR}/math/pari

USES=		perl5
USE_PERL5=	configure

CONFIGURE_ARGS=	parilib="-L${LOCALBASE}/lib -lpari" \
		paridir=`${MAKE} -C ${PORTSDIR}/math/pari -V WRKSRC`

post-patch:
	${REINPLACE_CMD} -e 's/2001004/2003000/' ${WRKSRC}/Makefile.PL

post-clean:
	${MAKE} -C ${PORTSDIR}/math/pari -DBATCH clean

.include <bsd.port.mk>
