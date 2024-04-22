PORTNAME=	gp2c
DISTVERSION=	0.0.13
CATEGORIES=	math
MASTER_SITES=	http://pari.math.u-bordeaux.fr/pub/pari/GP2C/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Package for translating GP routines into C
WWW=		https://pari.math.u-bordeaux.fr/pub/pari/manuals/gp2c/gp2c.html

LICENSE=	GPLv2

LIB_DEPENDS=	libpari.so:math/pari

USES=		perl5

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

TEST_TARGET=	check

.include <bsd.port.mk>
