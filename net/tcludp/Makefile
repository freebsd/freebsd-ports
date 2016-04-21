# Created by: Frank Fenor <frank@fenor.de>
# $FreeBSD$

PORTNAME=	tcludp
PORTVERSION=	1.0.11
CATEGORIES=	net tcl
MASTER_SITES=	SF

MAINTAINER=	frank@fenor.de
COMMENT=	UDP extension for TCL

LICENSE=	TclTk
LICENSE_NAME=	Tcl/Tk License
LICENSE_FILE=	${WRKSRC}/license.terms
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		tcl:tea
USE_LDCONFIG=	${PREFIX}/lib/${TCL_PKG}
WRKSRC=		${WRKDIR}/${PORTNAME}

TEST_TARGET=	test

PLIST_FILES=	lib/${TCL_PKG}/lib${TCL_PKG}.so \
		lib/${TCL_PKG}/pkgIndex.tcl \
		%%PORTDOCS%%man/mann/udp.n.gz

.include <bsd.port.mk>
