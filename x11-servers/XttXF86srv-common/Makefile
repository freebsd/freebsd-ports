# New ports collection makefile for:	Common Files for Xservers with Xtt
# Version required:	1.0
# Date created:		15 April 1998
# Whom:			Taguchi Takeshi <taguchi@tohoku.iij.ad.jp>
#
# $Id: Makefile,v 1.10 1998/12/05 06:12:16 kuriyama Exp $
#

DISTNAME=	xc
PKGNAME?=	xtt-common-1.0
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.xfree86.org/pub/XFree86/3.3.2/source/ \
		ftp://xfree86.cdrom.com/pub/XFree86/3.3.2/source/ \
		http://hawk.ise.chuo-u.ac.jp/student/person/tshiozak/x-tt/dists/ \
		ftp://www.tohoku.iij.ad.jp/xtt/
DISTFILES=	X332src-1.tgz xtt-1.0.tar.gz xttdoc10-to-pl00.diff.gz

PATCH_SITES=	ftp://ftp.xfree86.org/pub/XFree86/3.3.2/fixes/ \
		ftp://xfree86.cdrom.com/pub/XFree86/3.3.2/fixes/ \
		http://hawk.ise.chuo-u.ac.jp/student/person/tshiozak/x-tt/dists/ \
		ftp://www.tohoku.iij.ad.jp/xtt/
PATCHFILES=	3.3.2-patch1 3.3.2-patch2 3.3.2-patch3 \
		xtt10-to-pl00.diff.gz

MAINTAINER=	taguchi@tohoku.iij.ad.jp

LIB_DEPENDS=	ttf.3:${PORTSDIR}/print/freetype

.if !defined(XDM_DES) && defined(USA_RESIDENT)
.if ${USA_RESIDENT} == NO
MASTER_SITES+=	ftp://psych.psy.uq.oz.au/pub/X11R5/ \
		ftp://ftp.internat.freebsd.org/pub/FreeBSD/X11-Crypto/ \
		ftp://ftp3.za.freebsd.org/pub/FreeBSD/X11-Crypto/
DISTFILES+=	Wraphelp.c
IGNOREFILES=	Wraphelp.c
.endif
.endif
EXTRACT_ONLY=	X332src-1.tgz xtt-1.0.tar.gz
# can't use USE_X_PREFIX here
PREFIX=		${X11BASE}
MTREE_FILE=	/etc/mtree/BSD.x11.dist
WRKDIR=		${WRKDIRPREFIX}${.CURDIR}/../XttXF86srv-common/work
WRKSRC=		${WRKDIR}/xc
XTTDIR=		${WRKDIR}/xtt-1.0
DOCDIR=		${PREFIX}/share/doc/Xtt
DIST_SUBDIR=		xc
PATCH_DIST_STRIP=	-p1
ALL_SERVER=	XF86_8514 XF86_AGX XF86_I128 XF86_Mach32 XF86_Mach64 \
		XF86_Mach8 XF86_Mono XF86_P9000 XF86_S3 XF86_S3V \
		XF86_SVGA XF86_VGA16 XF86_W32
ALL_SERVER+=	XF98_EGC XF98_GA968 XF98_GANBWAP XF98_MGA XF98_NEC480 \
		XF98_NECS3 XF98_NKVNEC XF98_PWLB XF98_PWSKB XF98_SVGA \
		XF98_TGUI XF98_WABEP XF98_WABS XF98_WSNA
HOSTDEFLOCAL=	${WRKDIR}/host.def.local
.if defined(SERVER) && (${SERVER} == xfs)
ALL_TARGET=	xfs
HOSTDEFSRV=
HOSTDEFDST=	${WRKSRC}/config/cf/host.def.xfs
.else
ALL_TARGET=	World
.if (defined(THIS_SERVER_ONLY) && ${THIS_SERVER_ONLY} == YES)
HOSTDEFSRV=	${FILESDIR}/host.def.${SERVER}
.else
HOSTDEFSRV=	${FILESDIR}/host.def.ALL
.endif
HOSTDEFDST=	${WRKSRC}/config/cf/host.def
.endif
BINOWN=		root
BINGRP=		wheel

.if defined(SERVER)
CONFIGURE_COOKIE=	${WRKDIR}/.configure_done.${SERVER}
BUILD_COOKIE=		${WRKDIR}/.build_done.${SERVER}
INSTALL_COOKIE=		${WRKDIR}/.install_done.${SERVER}
PACKAGE_COOKIE=		${WRKDIR}/.package_done.${SERVER}
TMPPLIST=		${WRKDIR}/.PLIST.${SERVER}.mktmp
.else
PACKAGE_COOKIE=		${WRKDIR}/.package_done.common
TMPPLIST=		${WRKDIR}/.PLIST.common.mktmp
.endif

.if !defined(SERVER) && !exists(${WRKDIR}/.build_done)
BROKEN=		This port is dummy.
.endif

.include <bsd.port.pre.mk>

.if defined(SERVER)
.if ${SERVER} != xfs
pre-fetch:
	@( \
	${ECHO_MSG} "*******" ; \
	${ECHO_MSG} "NOTICE:" ; \
	${ECHO_MSG} "*******" ; \
	${ECHO_MSG} " If you want to build/install this ${SERVER} server only," ; \
	${ECHO_MSG} "you should execute:" ; \
	${ECHO_MSG} "  # make THIS_SERVER_ONLY=YES" ; \
	${ECHO_MSG} "If the THIS_SERVER_ONLY flag not be set, this port will" ; \
	${ECHO_MSG} "build ALL Xtt-X servers, and install only ${SERVER}." ; \
	${ECHO_MSG} "This means you will need more disk space and CPU times." ; \
	${ECHO_MSG} "" )
.endif
.endif

pre-patch:
	@( ${PATCH} ${PATCH_DIST_ARGS} < ${XTTDIR}/xtt-1.0.diff; \
	${GZCAT} ${DISTDIR}/${DIST_SUBDIR}/xttdoc10-to-pl00.diff.gz | \
	${PATCH} -s -d ${XTTDIR} )

pre-configure:
	@( \
	${CP} ${FILESDIR}/Imakefile ${WRKDIR} ; \
	(cd ${WRKDIR} ; ${XMKMF} ; ${SETENV} ${MAKE_ENV} DISTDIR=${DISTDIR} WRKDIR=${WRKDIR} FILESDIR=${FILESDIR} ${MAKE}) ; \
	${CAT} ${HOSTDEFLOCAL} ${HOSTDEFSRV} > ${HOSTDEFDST} )

.if defined(SERVER)
.if (defined(THIS_SERVER_ONLY) && ${THIS_SERVER_ONLY} == YES) || ${SERVER} == xfs
post-configure:
	@${TOUCH} ${TOUCH_FLAGS} ${CONFIGURE_COOKIE}

post-build:
	@${TOUCH} ${TOUCH_FLAGS} ${BUILD_COOKIE}
.else
post-configure:
	@ ( \
	cd ${WRKDIR} ; \
	for i in ${ALL_SERVER} ; do \
		${TOUCH} ${TOUCH_FLAGS} `${BASENAME} ${CONFIGURE_COOKIE} .${SERVER}`.$${i} ; \
	done )

post-build:
	@ ( \
	cd ${WRKDIR} ; \
	for i in ${ALL_SERVER} ; do \
		${TOUCH} ${TOUCH_FLAGS} `${BASENAME} ${BUILD_COOKIE} .${SERVER}`.$${i} ; \
	done )
.endif
.endif

.if !defined(SERVER)
do-install:
	@( \
	cd ${WRKSRC}/lib/font; \
	${SETENV} ${MAKE_ENV} ${MAKE} install; \
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib; \
	${INSTALL_SCRIPT} ${FILESDIR}/mkfontdir.pl ${PREFIX}/bin; \
	${MKDIR} ${DOCDIR}; \
	${INSTALL_DATA} ${XTTDIR}/xtt10-*.eng ${DOCDIR}; \
	${INSTALL_DATA} ${XTTDIR}/xtt10-*.jis ${DOCDIR} )
.if ${PORTOBJFORMAT} == "aout"
	${LN} -sf libfont.so.1.0 ${PREFIX}/lib/libfont.so
.endif
.elif defined(SERVER) && ${SERVER} == xfs
do-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${INSTALL_PROGRAM} ${WRKSRC}/programs/xfs/xfs ${PREFIX}/bin/xfs.xtt
.else
do-install:
	@( \
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${INSTALL_PROGRAM} ${WRKSRC}/programs/Xserver/${SERVER} ${PREFIX}/bin/${SERVER}.xtt; \
	${LN} -fs ${PREFIX}/bin/${SERVER}.xtt ${PREFIX}/bin/X )
.endif

post-install:
	@${TOUCH} ${TOUCH_FLAGS} ${INSTALL_COOKIE}

post-package:
	@${TOUCH} ${TOUCH_FLAGS} ${PACKAGE_COOKIE}

.include <bsd.port.post.mk>
