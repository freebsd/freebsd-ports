# New ports collection makefile for:	lyx
# Version required:	0.10.6
# Date created:		Sa  12 Okt 1996 19:20:51 MET DST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.9 1997/10/04 14:53:05 andreas Exp $
#

DISTNAME=	lyx-0.10.7
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.via.ecp.fr/pub/lyx/beta_stable/

MAINTAINER=	andreas@FreeBSD.ORG

BUILD_DEPENDS=	latex:${PORTSDIR}/print/teTeX
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX \
		ispell:${PORTSDIR}/textproc/ispell
LIB_DEPENDS=	xforms\\.0\\.:${PORTSDIR}/x11/xforms \
		Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-extra-lib=${X11BASE}/lib --with-extra-inc="${X11BASE}/include ${X11BASE}/include/X11"
MAN1=		lyx.1

.include <bsd.port.mk>
