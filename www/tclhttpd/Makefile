# New ports collection makefile for:	tclhttpd
# Date created:		27 Apr 2000
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	tclhttpd
PORTVERSION=	3.2.1
CATEGORIES=	www tcl${TCL_VER}
MASTER_SITES=	${MASTER_SITE_TCLTK}
MASTER_SITE_SUBDIR=	httpd
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	mi@aldan.algebra.com

RUN_DEPENDS=	${LOCALBASE}/lib/tcllib0.8/pkgIndex.tcl:${PORTSDIR}/devel/tcllib
LIB_DEPENDS=	tcl${TCL_VER}:${PORTSDIR}/lang/tcl${TCL_VER}

TCL_DVER?=	8.3
TCL_VER=	${TCL_DVER:S/.//}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl="${LOCALBASE}/lib/tcl${TCL_DVER}" \
		--with-tclinclude="${LOCALBASE}/include/tcl${TCL_DVER}"

RCD=	${LOCALBASE}/etc/rc.d/tclhttpd.sh

.include <bsd.port.pre.mk>
SHLIB_NAME!=	${MAKE} -f "${FILESDIR}/Makefile.lib" ech
PLIST_SUB+=	TCL_VER=${TCL_VER} PORTVERSION=${PORTVERSION} \
		SHLIB_NAME=${SHLIB_NAME}

do-build:
	cd ${WRKSRC} && ${MAKE_ENV} ${MAKE} -j 2 TCL_DVER="${TCL_DVER}" \
		FILESDIR="${FILESDIR}" -f "${FILESDIR}/Makefile.lib"

pre-install:
	${MKDIR} ${LOCALBASE}/tclhttpd/custom

post-install:
	test -e ${RCD} || ${SED} \
		"s%COMMAND_LINE%${LOCALBASE}/bin/tclsh${TCL_DVER} ${PREFIX}/bin/httpd.tcl%" \
		< ${FILESDIR}/tclhttpd.sh > ${RCD}
	${CHOWN} -R nobody ${LOCALBASE}/share/${PORTNAME}${PORTVERSION}
	${CHMOD} +x ${RCD}
	${INSTALL_DATA} ${WRKSRC}/${SHLIB_NAME} \
		${LOCALBASE}/lib/${PORTNAME}${PORTVERSION}/${SHLIB_NAME}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/httpd.tcl \
		${WRKSRC}/bin/httpdthread.tcl ${LOCALBASE}/bin/
	${SED} 's%@VER@%${PORTVERSION}%g' < ${WRKSRC}/bin/tclhttpd.rc \
		> ${LOCALBASE}/etc/tclhttpd.rc.default
	cd ${LOCALBASE}/etc; test -e tclhttpd.rc || \
		${CP} -p tclhttpd.rc.default tclhttpd.rc
	${SED} 's%@LIB@%${SHLIB_NAME}%g' < \
		${FILESDIR}/pkgIndex.tcl >> \
		${LOCALBASE}/lib/${PORTNAME}${PORTVERSION}/pkgIndex.tcl

.include <bsd.port.post.mk>
