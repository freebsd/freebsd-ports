# New ports collection makefile for:	ndir
# Date created:			Jun 16, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	ndir
PORTVERSION=	0.8.5
CATEGORIES=	sysutils
MASTER_SITES=	http://www.Informatik.Uni-Oldenburg.DE/~mw/software/
DISTNAME=	NDir-${PORTVERSION}
EXTRACT_SUFX=	-1.tar.gz

MAINTAINER=	markp@FreeBSD.org

USE_GMAKE=	yes
USE_REINPLACE=	yes
ALL_TARGET=	compile
CFLAGS+=	-DNO_THOUSANDS_GROUPING
MAN1=		ndir.1
MLINKS=		ndir.1 lv.1 ndir.1 lw.1

post-patch:
	@${REINPLACE_CMD} -e "s/^export GLOBAL.+//g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ndir ${PREFIX}/bin
	${LN} -sf ndir ${PREFIX}/bin/lw
	${LN} -sf ndir ${PREFIX}/bin/lv
	${INSTALL_MAN} ${WRKSRC}/ndir.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
