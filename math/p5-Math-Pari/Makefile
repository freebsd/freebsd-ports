# Created by: Michael Haro <mharo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Math-Pari
PORTVERSION=	2.01080800
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/00$//}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	PARI - numerical/scientific/number-theoretic calculations

BUILD_DEPENDS=	${NONEXISTENT}:math/pari:configure
LIB_DEPENDS=	libpari.so:math/pari

USES=		perl5 zip
USE_PERL5=	configure

CONFIGURE_ARGS=	parilib="-L${LOCALBASE}/lib -lpari" \
		paridir=`${MAKE} -C ${PORTSDIR}/math/pari -V WRKSRC`

post-patch:
	@${REINPLACE_CMD} -e 's|2001007|2003000|' ${WRKSRC}/Makefile.PL

post-clean:
	@${MAKE_CMD} -C ${PORTSDIR}/math/pari -DBATCH clean

.include <bsd.port.mk>
