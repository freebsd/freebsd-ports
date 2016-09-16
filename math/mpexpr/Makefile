# Created by: Chuck Hein <geekdude@pacbell.net>
# $FreeBSD$

PORTNAME=	mpexpr
PORTVERSION=	1.2
CATEGORIES=	math tcl
MASTER_SITES=	SF

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Multiple precision math for Tcl

LICENSE=	TclTk
LICENSE_NAME=	Tcl/Tk License
LICENSE_FILE=	${WRKSRC}/../LICENSE.TERMS
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

WRKSRC=		${WRKDIR}/${DISTNAME}/unix
PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}
USES+=		gmake tcl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-tcl=${TCL_LIBDIR}
CONFIGURE_ENV+=	TCL_INC_DIR=${TCL_INCLUDEDIR} \
		TCL_LIB_DIR=${TCL_LIBDIR}

PLIST_FILES=	lib/Mpexpr12/libMpexpr12.so \
		lib/Mpexpr12/pkgIndex.tcl \
		man/mann/mpexpr.n.gz

post-patch:
	${REINPLACE_CMD} -e 's|\.\.||' ${WRKSRC}/pkgIndex.tcl.in
	${REINPLACE_CMD} -e '/set VERBOSE/s|0|1|' ${WRKSRC}/../tests/defs

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/Mpexpr12
	${INSTALL_PROGRAM} ${WRKSRC}/libMpexpr12.so ${STAGEDIR}${PREFIX}/lib/Mpexpr12
	${INSTALL_DATA} ${WRKSRC}/pkgIndex.tcl ${STAGEDIR}${PREFIX}/lib/Mpexpr12
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/doc/mpexpr.man ${STAGEDIR}${PREFIX}/man/mann/mpexpr.n

do-test: build
	cd ${WRKSRC} && ${MAKE_CMD} test

.include <bsd.port.mk>
