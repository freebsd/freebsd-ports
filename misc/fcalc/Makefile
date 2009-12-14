# New ports collection makefile for:	fcalc
# Date Created:				11 jun 2006
# Whom:					Serge Gagnon <serge.gagnon@b2b2c.ca>
#
# $FreeBSD$
#

PORTNAME=	fcalc
PORTVERSION=	1
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	ftp://quenix2.dyndns.org/FreeBSD/ports/distfiles/
DISTNAME=	${PORTNAME}-tcl

MAINTAINER=	ports@FreeBSD.org
COMMENT=	F/Calc is a calculator for photographic formulas

RUN_DEPENDS=	${LOCALBASE}/lib/tix8.1/Tix.tcl:${PORTSDIR}/x11-toolkits/tix

NO_BUILD=	yes
USE_XORG=	x11 xt
USE_TK_RUN=	84

WRKSRC=	${WRKDIR}/${PORTNAME}-1.00

post-patch:
	${REINPLACE_CMD} -e 's|BINDIR=/usr/local/bin|BINDIR=${PREFIX}/bin|' \
		-e 's|LIBDIR=/usr/local/lib/fcalc|LIBDIR=${PREFIX}/lib/fcalc|' \
		${WRKSRC}/INSTALL
	${REINPLACE_CMD} -e 's|netscape|firefox|' ${WRKSRC}/Dialogs.tcl
	${REINPLACE_CMD} -e 's|exec wish|exec wish8.4|' \
		-e 's|^set libDir.*||' -e 's|^#set libDir|set libDir|' \
		${WRKSRC}/fcalc

do-install:
	cd ${WRKSRC}; ./INSTALL

.include <bsd.port.mk>
