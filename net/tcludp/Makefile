# Created by: Frank Fenor <frank@fenor.de>
# $FreeBSD$

PORTNAME=	tcludp
PORTVERSION=	1.0.11
CATEGORIES=	net tcl
MASTER_SITES=	SF

MAINTAINER=	frank@fenor.de
COMMENT=	UDP extension for TCL

USES=		tcl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-tcl=${TCL_LIBDIR} \
		--exec-prefix=${PREFIX}
USE_LDCONFIG=	${PREFIX}/lib/udp${PORTVERSION}
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	lib/udp${PORTVERSION}/libudp${PORTVERSION}.so \
		lib/udp${PORTVERSION}/pkgIndex.tcl \
		%%PORTDOCS%%man/mann/udp.n.gz

.include <bsd.port.mk>
