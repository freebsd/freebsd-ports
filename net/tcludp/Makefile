PORTNAME=	tcludp
PORTVERSION=	1.0.11
PORTREVISION=	1
CATEGORIES=	net tcl
MASTER_SITES=	SF

MAINTAINER=	frank@fenor.de
COMMENT=	UDP extension for TCL
WWW=		https://tcludp.sourceforge.net/

LICENSE=	TclTk
LICENSE_NAME=	Tcl/Tk License
LICENSE_FILE=	${WRKSRC}/license.terms
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		tcl:tea
USE_LDCONFIG=	${PREFIX}/lib/${TCL_PKG}
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
WRKSRC=		${WRKDIR}/${PORTNAME}

TEST_TARGET=	test

PLIST_FILES=	lib/${TCL_PKG}/lib${TCL_PKG}.so \
		lib/${TCL_PKG}/pkgIndex.tcl \
		share/man/mann/udp.n.gz

.include <bsd.port.mk>
