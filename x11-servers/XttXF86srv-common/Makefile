# New ports collection makefile for:	Common Files for Xservers with Xtt
# Version required:	1.1
# Date created:		15 April 1998
# Whom:			Taguchi Takeshi <taguchi@tohoku.iij.ad.jp>
#
# $Id: Makefile,v 1.12 1999/01/02 19:11:10 sada Exp $
#

DISTNAME=	xc
PKGNAME?=	xtt-common-1.1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.xfree86.org/pub/XFree86/3.3.3/source/ \
		ftp://xfree86.cdrom.com/pub/XFree86/3.3.3/source/ \
		http://hawk.ise.chuo-u.ac.jp/student/person/tshiozak/x-tt/dists/1.x/ \
		ftp://www.tohoku.iij.ad.jp/xtt/
DISTFILES=	X333src-1.tgz xtt-1.1.tar.gz \
		xttdoc11-to-pl01.diff.gz

PATCH_SITES=	http://hawk.ise.chuo-u.ac.jp/student/person/tshiozak/x-tt/dists/1.x/ \
		ftp://www.tohoku.iij.ad.jp/xtt/
PATCHFILES=	xtt11-to-pl00.diff.gz xtt11pl00-to-pl01.diff.gz \
		xtt11pl01-to-pl02.diff.gz xtt11pl02-to-pl03.diff.gz

MAINTAINER=	taguchi@tohoku.iij.ad.jp

LIB_DEPENDS=	ttf.3:${PORTSDIR}/print/freetype
#RUN_DEPENDS+=	mkttfdir:${PORTSDIR}/print/perlftlib

.if !defined(USE_SHARED_WRKSRC) && defined(COMPILE_ALL_SERVERS_AT_ONCE)
USE_SHARED_WRKSRC= YES
.endif
.if !defined(XDM_DES) && defined(USA_RESIDENT) && ${USA_RESIDENT} == NO
MASTER_SITES+=	ftp://psych.psy.uq.oz.au/pub/X11R5/ \
		ftp://ftp.internat.freebsd.org/pub/FreeBSD/X11-Crypto/ \
		ftp://ftp3.za.freebsd.org/pub/FreeBSD/X11-Crypto/
DISTFILES+=	Wraphelp.c
IGNOREFILES=	Wraphelp.c
.endif
USE_X_PREFIX=	YES
EXTRACT_ONLY=	X333src-1.tgz xtt-1.1.tar.gz
BINOWN=		root
BINGRP=		wheel
MASTERDIR?=	${.CURDIR}/../XttXF86srv-common
FILESDIR=	${MASTERDIR}/files
PATCHDIR=	${MASTERDIR}/patches
.if defined(USE_SHARED_WRKSRC)
WRKDIR=		${MASTERDIR}/work
.endif
WRKSRC=		${WRKDIR}/xc
DIST_SUBDIR=	xc
XTTDIR=		${WRKDIR}/xtt-1.1
DOCDIR=		${PREFIX}/share/doc/Xtt
SERVER?=	common
PATCH_DIST_ARGS= -d ${WRKDIR} --forward --quiet -E ${PATCH_STRIP}
#PATCH_DIST_STRIP=	-p1

# ******************
# USE_SHARED_WRKSRC:
#  All Xtt ports require many disk space. Imagen, X source code will extract
#  under server and common ports dir. This variable save your disk space.
#  if this variable is defined, X source will only extract under common
#  ports. server ports will use this common's WRKSRC.
# COMPILE_ALL_SERVERS_AT_ONCE:
#  If this variable is defined, All server ports will build at once.
#  This variable will save your time, if you want to make all xtt packages.
# ******************
.if defined(USE_SHARED_WRKSRC)
CONFIGURE_COOKIE=	${WRKDIR}/.configure_done.${SERVER}
BUILD_COOKIE=		${WRKDIR}/.build_done.${SERVER}
INSTALL_COOKIE=		${WRKDIR}/.install_done.${SERVER}
PACKAGE_COOKIE=		${WRKDIR}/.package_done.${SERVER}
TMPPLIST=		${WRKDIR}/.PLIST.${SERVER}.mktmp
ALL_TARGET=		World
.if defined(COMPILE_ALL_SERVERS_AT_ONCE) && ${SERVER} != xfs
ALL_SERVER=	XF86_3DLabs XF86_8514 XF86_AGX XF86_I128 XF86_Mach32 \
	XF86_Mach64 XF86_Mach8 XF86_Mono XF86_P9000 XF86_S3 XF86_S3V \
	XF86_SVGA XF86_VGA16 XF86_W32 \
	XF98_EGC  XF98_GA968 XF98_GANBWAP XF98_MGA XF98_NEC480 \
	XF98_NECS3 XF98_NKVNEC XF98_SVGA XF98_TGUI XF98_PWLB XF98_PWSKB \
	XF98_WABEP XF98_WABS XF98_WSNA \
	common
HOSTDEFSRV=	${FILESDIR}/host.def.ALL
.else
ALL_SERVER=	${SERVER} common
HOSTDEFSRV=	${FILESDIR}/host.def.${SERVER}
.endif
.if ${SERVER} == xfs
HOSTDEFDST=	${WRKSRC}/config/cf/host.def.xfs
.else
HOSTDEFDST=	${WRKSRC}/config/cf/host.def
.endif
.else
ALL_SERVER=	${SERVER}
.if (${SERVER} == xfs)
ALL_TARGET=	xfs
HOSTDEFSRV=
HOSTDEFDST=	${WRKSRC}/config/cf/host.def.xfs
.elif (${SERVER} == common)
ALL_TARGET=	libfont
HOSTDEFSRV=	${FILESDIR}/host.def.${SERVER}
HOSTDEFDST=	${WRKSRC}/config/cf/host.def
.else
ALL_TARGET=	World
HOSTDEFSRV=	${FILESDIR}/host.def.${SERVER}
HOSTDEFDST=	${WRKSRC}/config/cf/host.def
.endif
.endif
HOSTDEFLOCAL=	${WRKDIR}/host.def.local

.include <bsd.port.pre.mk>

.if !defined(USE_SHARED_WRKSRC) && exists(${MASTERDIR}/work/.configure_done.${SERVER})
pre-extract:
	@( \
	 echo "ERROR:" ; \
	 echo "Xtt ${SERVER} ports have already extracted with" ; \
	 echo "\"USE_SHARED_WRKSRC\" option." ; \
	 false )
.endif

pre-patch:
	@( cd ${WRKSRC}; ${PATCH} -p1 -t -s < ${XTTDIR}/xtt-1.1.diff ; \
	   cd ${XTTDIR}; \
           ${GZCAT} ${DISTDIR}/${DIST_SUBDIR}/xttdoc11-to-pl01.diff.gz | \
             ${PATCH} -t -s )

pre-configure:
	@( \
	${CP} ${FILESDIR}/Imakefile ${WRKDIR} ; \
	(cd ${WRKDIR} ; ${XMKMF} ; \
          ${SETENV} ${MAKE_ENV} DISTDIR=${DISTDIR} WRKDIR=${WRKDIR} \
		FILESDIR=${FILESDIR} ${MAKE}) ; \
	${CAT} ${HOSTDEFLOCAL} ${HOSTDEFSRV} > ${HOSTDEFDST} )

.if ${SERVER} == common
do-install:
	@( \
	cd ${WRKSRC}/lib/font; \
	${SETENV} ${MAKE_ENV} ${MAKE} install; \
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib; \
	${INSTALL_SCRIPT} ${FILESDIR}/mkfontdir.pl ${PREFIX}/bin; \
	${MKDIR} ${DOCDIR}; \
	${INSTALL_DATA} ${XTTDIR}/[0A-Z]*.eng ${DOCDIR}; \
	${INSTALL_DATA} ${XTTDIR}/[0A-Z]*.jis ${DOCDIR} )
.if ${PORTOBJFORMAT} == "aout"
	${LN} -sf libfont.so.1.1 ${PREFIX}/lib/libfont.so
.endif
.elif ${SERVER} == xfs
do-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${INSTALL_PROGRAM} \
          ${WRKSRC}/programs/xfs/xfs ${PREFIX}/bin/xfs.xtt
.else
do-install:
	@( \
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${INSTALL_PROGRAM} \
          ${WRKSRC}/programs/Xserver/${SERVER} ${PREFIX}/bin/${SERVER}.xtt; \
	${LN} -fs ${PREFIX}/bin/${SERVER}.xtt ${PREFIX}/bin/X )
.endif

.if defined(USE_SHARED_WRKSRC)
post-configure:
	@( \
	cd ${WRKDIR} ; for i in ${ALL_SERVER} ; do \
		${TOUCH} ${TOUCH_FLAGS} `${BASENAME} ${CONFIGURE_COOKIE} .${SERVER}`.$${i} ; \
	done )

post-build:
	@( \
	cd ${WRKDIR} ; for i in ${ALL_SERVER} ; do \
		${TOUCH} ${TOUCH_FLAGS} `${BASENAME} ${BUILD_COOKIE} .${SERVER}`.$${i} ; \
	done )

post-install:
	@( \
	cd ${WRKDIR} ; 	${TOUCH} ${TOUCH_FLAGS} ${INSTALL_COOKIE} )

post-package:
	@( \
	cd ${WRKDIR} ; 	${TOUCH} ${TOUCH_FLAGS} ${PACKAGE_COOKIE} )
.endif

.include <bsd.port.post.mk>
