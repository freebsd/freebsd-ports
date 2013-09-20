# Created by: Frank Fenor <frank@fenor.de>
# $FreeBSD$

PORTNAME=	tcludp
PORTVERSION=	1.0.8
PORTREVISION=	1
CATEGORIES=	net tcl
MASTER_SITES=	SF

MAINTAINER=	frank@fenor.de
COMMENT=	UDP extension for TCL

USE_TCL=	84+
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-tcl=${TCL_LIBDIR}
USE_LDCONFIG=	${PREFIX}/lib/udp${PORTVERSION}
MANN=		udp.n
MANCOMPRESSED=	no

PLIST_FILES=	lib/udp1.0.8/libudp1.0.8.so \
		lib/udp1.0.8/pkgIndex.tcl
PLIST_DIRS=	lib/udp1.0.8

NO_STAGE=	yes
.include <bsd.port.mk>
