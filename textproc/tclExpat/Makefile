# Ports collection Makefile for:	TclExpat
# Date created:				Nov 16 2000
# Whom:					mi@aldan.algebra.com
#
# $FreeBSD$
#

PORTNAME=	TclExpat
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	textproc tcl83
MASTER_SITES=	http://www.zveno.com/in-tclxml/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	The TCL interface to Expat library

LIB_DEPENDS=	tcl${TCL_DVER}:${PORTSDIR}/lang/tcl${TCL_DVER} \
		expat.5:${PORTSDIR}/textproc/expat2

INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes

TCL_VERSION=	8.3
TCL_DVER=	${TCL_VERSION:S/.//}
PLIST_SUB+=	TCL_VERSION=${TCL_VERSION}

MAKEFILE=	${FILESDIR}/Makefile

# Remove the old version of expat bundled with the package:
post-extract:
	${RM} -rf ${WRKSRC}/expat

post-patch:
	${REINPLACE_CMD} -e 's/TCL_MAJOR_VERSION == 8 && TCL_MINOR_VERSION == 0/TCL_MAJOR_VERSION >= 8/;' \
		-e 's/xmlparse.h/expat.h/;' ${WRKSRC}/tclexpat.c

test: build
	${LN} -sf libtclexpat.so ${WRKSRC}/tclexpat.so
	cd ${WRKSRC} && tclsh${TCL_VERSION} test-break.tcl
	cd ${WRKSRC} && tclsh${TCL_VERSION} test-continue.tcl
	cd ${WRKSRC} && tclsh${TCL_VERSION} test-error.tcl

post-install:
	${MKDIR} ${LOCALBASE}/lib/tcl${TCL_VERSION}/${PORTNAME}
	${SED} 's|PREFIX|${PREFIX}|' < ${FILESDIR}/pkgIndex.tcl.in > \
		${LOCALBASE}/lib/tcl${TCL_VERSION}/${PORTNAME}/pkgIndex.tcl
.if !defined(NOPORTDOCS)
	${MKDIR} ${LOCALBASE}/share/doc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/README ${LOCALBASE}/share/doc/${PORTNAME}/
.endif

.include <bsd.port.mk>
