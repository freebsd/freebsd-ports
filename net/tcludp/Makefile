# New ports collection makefile for:	tcludp
# Date created:				24 March 2008
# Whom:					Frank Fenor <frank@fenor.de>
#
# $FreeBSD$
#

PORTNAME=	tcludp
PORTVERSION=	1.0.8
PORTREVISION=	1
CATEGORIES=	net tcl
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=tcludp

MAINTAINER=	frank@fenor.de
COMMENT=	UDP extension for TCL

USE_TCL=	82+
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-tcl=${TCL_LIBDIR}
USE_LDCONFIG=	${PREFIX}/lib/udp${PORTVERSION}
MANN=		udp.n
MANCOMPRESSED=	no

PLIST_FILES=	lib/udp1.0.8/libudp1.0.8.so \
		lib/udp1.0.8/pkgIndex.tcl
PLIST_DIRS=	lib/udp1.0.8

.include <bsd.port.mk>
