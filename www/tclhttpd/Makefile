# New ports collection makefile for: 	thttpd
# Date created:		27 Apr 2000
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	tclhttpd
PORTVERSION= 	3.0.3
CATEGORIES=	www tcl${TCL_VER}
MASTER_SITES=	${MASTER_SITE_TCLTK}
MASTER_SITE_SUBDIR=	httpd
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	mi@aldan.algebra.com

RUN_DEPENDS=	${LOCALBASE}/lib/tcllib0.4/pkgIndex.tcl:${PORTSDIR}/devel/tcllib
LIB_DEPENDS=	tcl${TCL_VER}:${PORTSDIR}/lang/tcl${TCL_VER}

TCL_DVER?=	8.3
TCL_VER=	${TCL_DVER:S/.//}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl="${LOCALBASE}/lib/tcl${TCL_DVER}" \
		--with-tclinclude="${LOCALBASE}/include/tcl${TCL_DVER}"

PLIST_SUB+=	TCL_VER=${TCL_VER} PORTVERSION=${PORTVERSION} \
	"LIBSUF=`echo ${PORTOBJFORMAT} | ${SED} -e s/elf/1/ -e s/aout/1.0/`"

RCD=	${LOCALBASE}/etc/rc.d/tclhttpd.sh

SCRIPTS_ENV+=	LOCALBASE=${LOCALBASE} WRKSRC=${WRKSRC}} \
		CFLAGS="${CFLAGS}" TCL_DVER=${TCL_DVER} \
		TCL_VER=${TCL_VER}

post-install:
	test -e ${RCD} || ${SED} \
		"s%COMMAND_LINE%${LOCALBASE}/bin/tclsh${TCL_DVER} ${PREFIX}/bin/httpd.tcl%" \
		< ${FILESDIR}/tclhttpd.sh > ${RCD}
	${MKDIR} ${LOCALBASE}/${PORTNAME}${PORTVERSION}
	${CHOWN} -R nobody ${LOCALBASE}/share/${PORTNAME}${PORTVERSION}
	#${LN} -sf ${LOCALBASE}/share/${PORTNAME}${PORTVERSION} \
	#	${LOCALBASE}/${PORTNAME}${PORTVERSION}/htdocs
	${CHMOD} +x ${RCD}
	${INSTALL_DATA} ${WRKSRC}/src/libcrypt.so.* \
		${WRKSRC}/src/liblimit.so.* ${WRKSRC}/src/libsetuid.so.* \
			${LOCALBASE}/lib/${PORTNAME}${PORTVERSION}/
	${INSTALL_SCRIPT} ${WRKSRC}/bin/httpd.tcl \
		${WRKSRC}/bin/httpdthread.tcl ${LOCALBASE}/bin/
	${INSTALL_DATA} ${WRKSRC}/bin/tclhttpd.rc ${LOCALBASE}/etc/
	${CAT} ${FILESDIR}/pkgIndex.tcl >> \
		${LOCALBASE}/lib/${PORTNAME}${PORTVERSION}/pkgIndex.tcl
	for f in ${LOCALBASE}/lib/${PORTNAME}${PORTVERSION}/lib*.so.* ; \
	do \
		${LN} -sf `basename $$f` \
			`echo $$f | ${SED} 's@\(.*\.so\)\..*@\1@'` ; \
	done

do-build:	# empty -- everything done by ${SCRIPTDIR}/pre-build

.include <bsd.port.mk>
