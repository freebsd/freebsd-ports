# New ports collection makefile for:	lyx
# Version required:	0.10.6
# Date created:		Sa  12 Okt 1996 19:20:51 MET DST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.18 1998/08/01 09:07:02 andreas Exp $
#

DISTNAME=	lyx-0.12.1pre6
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.via.ecp.fr/pub/lyx/stable/ \
		ftp://la1ad.uio.no/pub/lyx/                

MAINTAINER=	andreas@FreeBSD.ORG

BUILD_DEPENDS=	latex:${PORTSDIR}/print/teTeX
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX
.if defined(WITH_ISPELL)
RUN_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
.endif
LIB_DEPENDS=	xforms\\.0\\.:${PORTSDIR}/x11-toolkits/xforms \
		Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CXXFLAGS="${CFLAGS}"
STRIP=
CONFIGURE_ARGS= --with-extra-lib=${X11BASE}/lib --with-extra-inc="${X11BASE}/include ${X11BASE}/include/X11"
MAN1=		lyx.1

pre-fetch:
.if !defined(WITH_ISPELL)
	@${ECHO_MSG} "if you want this port build with spell checker type"
	@${ECHO_MSG} "make WITH_ISPELL=yes"
.endif

post-install:
	@strip ${PREFIX}/bin/lyx

.include <bsd.port.mk>
