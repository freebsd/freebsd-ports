# Created by: mi@aldan.algebra.com
# $FreeBSD$

PORTNAME=	TclExpat
PORTVERSION=	1.1
PORTREVISION=	7
CATEGORIES=	textproc tcl
#MASTER_SITES=	http://T32.TecNik93.com/FreeBSD/others_ports/${PORTNAME}/sources/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Tcl interface to Expat library

BROKEN=		unfetchable

LIB_DEPENDS=	libexpat.so:textproc/expat2

USE_LDCONFIG=	yes

USES=		tcl uidfix
PLIST_SUB+=	TCL_VERSION=${TCL_VER}

MAKEFILE=	${FILESDIR}/Makefile
MAKE_ENV+=	TCL_VERSION=${TCL_VER}

OPTIONS_DEFINE=	DOCS

# Remove the old version of expat bundled with the package:
post-extract:
	${RM} -r ${WRKSRC}/expat

post-build test:
	${LN} -sf libtclexpat.so ${WRKSRC}/tclexpat.so
	cd ${WRKSRC} && ${TCLSH} test-break.tcl
	cd ${WRKSRC} && ${TCLSH} test-continue.tcl
	cd ${WRKSRC} && ${TCLSH} test-error.tcl

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${SED} 's|PREFIX|${PREFIX}|' < ${FILESDIR}/pkgIndex.tcl.in > \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}/pkgIndex.tcl
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
