# Ports collection Makefile for:	TclExpat
# Date created:				Nov 16 2000
# Whom:					mi@aldan.algebra.com
#
# $FreeBSD$
#

PORTNAME=	TclExpat
PORTVERSION=	1.1
PORTREVISION=	5
CATEGORIES=	textproc tcl84
MASTER_SITES=	http://people.tecnik93.com/~itetcu/FreeBSD/others_ports/${PORTNAME}/sources/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	The TCL interface to Expat library

LIB_DEPENDS=	tcl${TCL_DVER}:${PORTSDIR}/lang/tcl${TCL_DVER} \
		expat:${PORTSDIR}/textproc/expat2

USE_LDCONFIG=	yes

TCL_VERSION?=	8.4
TCL_DVER=	${TCL_VERSION:S/.//}
PLIST_SUB+=	TCL_VERSION=${TCL_VERSION}

MAKEFILE=	${FILESDIR}/Makefile
MAKE_ENV+=	TCL_VERSION=${TCL_VERSION}

# Remove the old version of expat bundled with the package:
post-extract:
	${RM} -rf ${WRKSRC}/expat

post-build test:
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
