# New ports collection makefile for:	lyx
# Version required:	0.10.6
# Date created:		Sa  12 Okt 1996 19:20:51 MET DST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id$
#

DISTNAME=	lyx-0.10.6
CATEGORIES+=	print
MAINTAINER=	Andreas Klemm <andreas@klemm.gtn.com>

MASTER_SITES=	ftp://ftp.via.ecp.fr/pub/lyx/

BUILD_DEPENDS=	latex:${PORTSDIR}/print/teTeX
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX \
		ispell:${PORTSDIR}/misc/ispell
LIB_DEPENDS=	xforms\\.0\\.:${PORTSDIR}/x11/xforms \
		Xpm\\.4\\.:${PORTSDIR}/graphics/xpm \

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-extra-lib=/usr/X11R6/lib --with-extra-inc="/usr/X11R6/include /usr/X11R6/include/X11"

post-install:   
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/lyx.1
.endif

.include <bsd.port.mk>
