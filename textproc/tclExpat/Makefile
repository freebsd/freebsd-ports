# Created by: mi@aldan.algebra.com
# $FreeBSD$

PORTNAME=	TclExpat
PORTVERSION=	1.1
PORTREVISION=	6
CATEGORIES=	textproc tcl
MASTER_SITES=	http://T32.TecNik93.com/FreeBSD/others_ports/${PORTNAME}/sources/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	The TCL interface to Expat library

LIB_DEPENDS=	expat:${PORTSDIR}/textproc/expat2

USE_LDCONFIG=	yes

USE_TCL=	84+
PLIST_SUB+=	TCL_VERSION=${TCL_VER}

MAKEFILE=	${FILESDIR}/Makefile
MAKE_ENV+=	TCL_VERSION=${TCL_VER}

NO_STAGE=	yes
# Remove the old version of expat bundled with the package:
post-extract:
	${RM} -rf ${WRKSRC}/expat

post-build test:
	${LN} -sf libtclexpat.so ${WRKSRC}/tclexpat.so
	cd ${WRKSRC} && ${TCLSH} test-break.tcl
	cd ${WRKSRC} && ${TCLSH} test-continue.tcl
	cd ${WRKSRC} && ${TCLSH} test-error.tcl

post-install:
	${MKDIR} ${LOCALBASE}/lib/tcl${TCL_VER}/${PORTNAME}
	${SED} 's|PREFIX|${PREFIX}|' < ${FILESDIR}/pkgIndex.tcl.in > \
		${LOCALBASE}/lib/tcl${TCL_VER}/${PORTNAME}/pkgIndex.tcl
.if !defined(NOPORTDOCS)
	${MKDIR} ${LOCALBASE}/share/doc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/README ${LOCALBASE}/share/doc/${PORTNAME}/
.endif

.include <bsd.port.mk>
