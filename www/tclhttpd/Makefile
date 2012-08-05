# New ports collection makefile for:	tclhttpd
# Date created:		27 Apr 2000
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	tclhttpd
PORTVERSION=	3.5.1
PORTREVISION=	3
CATEGORIES=	www tcl
MASTER_SITES=	${MASTER_SITE_TCLTK}
MASTER_SITE_SUBDIR=	httpd
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	An http-server implemented in TCL

RUN_DEPENDS=	dtplite:${PORTSDIR}/devel/tcllib

USE_RC_SUBR=	tclhttpd
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl="${TCL_LIBDIR}"	\
		--with-tclinclude="${TCL_INCLUDEDIR}"

MAKE_JOBS_SAFE=	yes
USE_TCL=	84+
MAN1=		tclhttpd.1

.include <bsd.port.pre.mk>

SHLIB_NAME!=	${MAKE} -f "${FILESDIR}/Makefile.lib" -V SHLIB_NAME
PLIST_SUB+=	PORTVERSION=${PORTVERSION} \
		SHLIB_NAME=${SHLIB_NAME}
MAKE_ENV+=	TCLSH_PROG=${TCLSH} FILESDIR="${FILESDIR}" TCL_DVER=${TCL_VER}
SCRIPTS_ENV+=	TCL_DVER=${TCL_VER}
SUB_LIST+=	TCL_DVER=${TCL_VER}

do-build:
	${MAKE_ENV} ${MAKE} -C ${WRKSRC} ${MAKE_ARGS}	\
		FILESDIR="${FILESDIR}"	\
		${_MAKE_JOBS} -f "${FILESDIR}/Makefile.lib"

pre-su-install:
	${MKDIR} ${PREFIX}/tclhttpd/custom

post-install:
	${CHOWN} -R nobody ${DATADIR}${PORTVERSION}
	${INSTALL_DATA} ${WRKSRC}/${SHLIB_NAME} \
		${PREFIX}/lib/${PORTNAME}${PORTVERSION}/${SHLIB_NAME}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/httpd.tcl \
		${WRKSRC}/bin/httpdthread.tcl ${PREFIX}/bin/
	${SED} 's%@VER@%${PORTVERSION}%g' < ${WRKSRC}/bin/tclhttpd.rc \
		> ${PREFIX}/etc/tclhttpd.rc.default
	cd ${PREFIX}/etc; test -e tclhttpd.rc || \
		${CP} -p tclhttpd.rc.default tclhttpd.rc
	${SED} 's%@LIB@%${SHLIB_NAME}%g' < \
		${FILESDIR}/pkgIndex.tcl >> \
		${PREFIX}/lib/${PORTNAME}${PORTVERSION}/pkgIndex.tcl

.include <bsd.port.post.mk>
