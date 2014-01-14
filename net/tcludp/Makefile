# Created by: Frank Fenor <frank@fenor.de>
# $FreeBSD$

PORTNAME=	tcludp
PORTVERSION=	1.0.8
PORTREVISION=	1
CATEGORIES=	net tcl
MASTER_SITES=	SF

MAINTAINER=	frank@fenor.de
COMMENT=	UDP extension for TCL

USES=		tcl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-tcl=${TCL_LIBDIR} \
		--exec-prefix=${PREFIX}
USE_LDCONFIG=	${PREFIX}/lib/udp${PORTVERSION}

PLIST_FILES=	lib/udp1.0.8/libudp1.0.8.so \
		lib/udp1.0.8/pkgIndex.tcl \
		man/mann/udp.n.gz
PLIST_DIRS=	lib/udp1.0.8

.include <bsd.port.mk>
