# Created by: b.f. <bf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ltl2ba
PORTVERSION=	1.3
CATEGORIES=	math
MASTER_SITES=	http://www.lsv.fr/~gastin/ltl2ba/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast translation from LTL formulae to Buchi automata

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

CFLAGS+=	-DNXT

MAKE_ARGS=	CC=${CC} CFLAGS="${CFLAGS}"

ALL_TARGET=	ltl2ba

PLIST_FILES=	bin/ltl2ba

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ltl2ba ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
