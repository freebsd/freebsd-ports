# New ports collection makefile for:	Common Files for Xservers with Xtt
# Date created:		15 April 1998
# Whom:			Taguchi Takeshi <taguchi@tohoku.iij.ad.jp>
#
# $FreeBSD$
#

PORTNAME?=	xtt-common
PORTVERSION=	${VERSION}.${PATCHLEVEL}
PORTREVISION=	1
CATEGORIES=	x11-servers
MASTER_SITES=	${MASTER_SITE_XFREE} \
		http://X-TT.dsl.gr.jp/dists/1.x/${VERSION}/
MASTER_SITE_SUBDIR=	${XFREE_VERSION}
DISTFILES=	X336src-1.tgz xtt-${VERSION}.tgz

PATCH_SITES=	${MASTER_SITE_XFREE:S,%SUBDIR%/source,${XFREE_VERSION}/fixes,}
PATCHFILES=	fix-01-r128 fix-04-s3trio3d2x fix-05-s3trio3d fix-06-s3trio3d2x\
		fix-07-s3trio64v2gx+netfinity fix-08-s3savage_ix+mx

MAINTAINER?=	taguchi@tohoku.iij.ad.jp
COMMENT?=	Common files for X True Type Servers

RUN_DEPENDS+=	mkttfdir:${PORTSDIR}/print/perlftlib

USE_SUBMAKE=	yes
XFREE_VERSION=	3.3.6
VERSION=	1.3
PATCHLEVEL=	1
SERVER?=	common
INSTALLS_SHLIB=	yes
.if !defined(USE_SHARED_WRKSRC) && defined(COMPILE_ALL_SERVERS_AT_ONCE)
USE_SHARED_WRKSRC=	YES
.endif
.if !defined(XDM_DES) && defined(USA_RESIDENT) && ${USA_RESIDENT} == NO
MASTER_SITES+=	ftp://psych.psy.uq.oz.au/pub/X11R5/ \
		ftp://ftp.internat.freebsd.org/pub/FreeBSD/X11-Crypto/ \
		ftp://ftp3.za.freebsd.org/pub/FreeBSD/X11-Crypto/
DISTFILES+=	Wraphelp.c
IGNOREFILES=	Wraphelp.c
.endif
USE_X_PREFIX=	YES
USE_FREETYPE=	YES
EXTRACT_ONLY=	X336src-1.tgz xtt-${VERSION}.tgz
BINOWN=		root
BINGRP=		wheel
MASTERDIR?=	${.CURDIR}/../XttXF86srv-common
FILESDIR=	${MASTERDIR}/files
PATCHDIR=	${MASTERDIR}/files
.if defined(USE_SHARED_WRKSRC)
WRKDIR=		${MASTERDIR}/work
.endif
WRKSRC=		${WRKDIR}/xc
DIST_SUBDIR=	xc
XTTDIR=		${WRKDIR}/xtt-${VERSION}
.if !defined(PATCH_DEBUG)
XTTPATCHARGS=	-p1 -E -t -s -N
.else
XTTPATCHARGS=	-p1 -E
.endif
COREPATCHES=	shared-libfont-1.2.diff xfs-for-delayed-font-1.0.diff \
		make-xfs-only-1.3.diff xtt-xf335-changes.diff
XTTTARBALL=	xtt-core.tar
ADDPATCHES=	${XTTDIR}/contribute/xtt-xfsft-lib.patch
DOCDIR=		${PREFIX}/share/doc/Xtt
PATCH_DIST_STRIP=	-p1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502000
BROKEN=		"Does not compile"
.endif

.if ${XFREE86_VERSION} == 4
BUILD_DEPENDS+=	xmkmf:${PORTSDIR}/devel/imake-4
.endif

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
SHARED_COOKIE=		${WRKDIR}/.compiled_by_other_server_ports
CONFIGURE_COOKIE=	${WRKDIR}/.configure_done.${SERVER}
BUILD_COOKIE=		${WRKDIR}/.build_done.${SERVER}
INSTALL_COOKIE=		${WRKDIR}/.install_done.${SERVER}
PACKAGE_COOKIE=		${WRKDIR}/.package_done.${SERVER}
TMPPLIST=		${WRKDIR}/.PLIST.${SERVER}.mktmp
.if ${SERVER} == common && exists(${SHARED_COOKIE}) && !defined(COMPILE_ALL_SERVERS_AT_ONCE)
EXTRACT_ONLY=
.endif
.if ${SERVER} == common && exists(${SHARED_COOKIE}) && !defined(COMPILE_ALL_SERVERS_AT_ONCE)
NO_BUILD=	YES
.endif
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
.else
ALL_SERVER=	${SERVER}
HOSTDEFSRV=	${FILESDIR}/host.def.${SERVER}
.endif

LOCALFILE=	host.def.local
HOSTDEFLOCAL=	${WRKDIR}/${LOCALFILE}
HOSTDEFDST=	${WRKSRC}/config/cf/${LOCALFILE}
HOSTDEFORG=	${WRKSRC}/config/cf/host.def
.if ${SERVER} == xfs
ALL_TARGET=	xfs
.elif ${SERVER} == common && !defined(COMPILE_ALL_SERVERS_AT_ONCE)
ALL_TARGET=	libfont
.else
ALL_TARGET=	World
.endif

pre-fetch:
.if defined(USE_SHARED_WRKSRC)
	@( \
	${ECHO} "************************************************************"; \
	${ECHO} "*  ALL PORTS COMMONLY USE x11/XttXF86srv-common/work !     *"; \
	${ECHO} "************************************************************")
.if defined(COMPILE_ALL_SERVERS_AT_ONCE)
	@( \
	${ECHO} "************************************************************"; \
	${ECHO} "*  ALL PORTS (except xfs) BUILD AT ONCE !                  *"; \
	${ECHO} "************************************************************")
.endif
.endif

.if !defined(USE_SHARED_WRKSRC) && exists(${MASTERDIR}/work/.configure_done.${SERVER})
pre-extract:
	@( \
	 ${ECHO} "ERROR:" ; \
	 ${ECHO} "Xtt ${SERVER} ports have already extracted with" ; \
	 ${ECHO} "\"USE_SHARED_WRKSRC\" option." ; \
	 ${FALSE} )
.endif

pre-patch:
	@( cd ${WRKSRC}; \
	   ${PATCH} -s < ${PATCHDIR}/xttpatch ; \
	   for i in ${COREPATCHES} ; do \
		${PATCH} ${XTTPATCHARGS} < ${XTTDIR}/$${i}; \
	   done; \
	   ${TAR} xf ${XTTDIR}/${XTTTARBALL} -C ${WRKSRC}/lib/font; \
	   for i in ${ADDPATCHES} ; do \
		${PATCH} ${XTTPATCHARGS} < $${i}; \
	   done )

pre-configure:
	@( ${CP} ${FILESDIR}/Imakefile ${WRKDIR} ; \
	   (cd ${WRKDIR} ; ${XMKMF} ; \
	    ${SETENV} ${SCRIPT_ENV} DISTDIR=${DISTDIR} WRKDIR=${WRKDIR} \
		FILESDIR=${FILESDIR} ${MAKE}) ; \
	   ${CAT} ${HOSTDEFLOCAL} ${HOSTDEFSRV} > ${HOSTDEFDST} ; \
	   ${ECHO_CMD} "#include <${LOCALFILE}>" >> ${HOSTDEFORG} )

.if ${SERVER} == common
do-install:
	@( \
	cd ${WRKSRC}/lib/font; \
	${SETENV} ${MAKE_ENV} ${MAKE} install; \
	${INSTALL_SCRIPT} ${FILESDIR}/mkfontdir.pl ${PREFIX}/bin; \
	${MKDIR} ${DOCDIR}; \
	${INSTALL_DATA} ${XTTDIR}/doc/[0A-Z]*.eng ${DOCDIR}; \
	${INSTALL_DATA} ${XTTDIR}/doc/[0A-Z]*.jis ${DOCDIR} )
.if ${PORTOBJFORMAT} == "aout"
	${LN} -sf libfont.so.1.2 ${PREFIX}/lib/libfont.so
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
	cd ${WRKDIR} ; \
	for i in ${ALL_SERVER} ; do \
		${TOUCH} ${TOUCH_FLAGS} `${BASENAME} ${CONFIGURE_COOKIE} .${SERVER}`.$${i} ; \
	done )
.if ${SERVER} != common || (${SERVER} == common && defined(COMPILE_ALL_SERVERS_AT_ONCE))
	@${TOUCH} ${TOUCH_FLAGS} ${SHARED_COOKIE}
.endif

post-build:
	@( \
	cd ${WRKDIR} ; for i in ${ALL_SERVER} ; do \
		${TOUCH} ${TOUCH_FLAGS} `${BASENAME} ${BUILD_COOKIE} .${SERVER}`.$${i} ; \
	done )
.if ${SERVER} != common || (${SERVER} == common && defined(COMPILE_ALL_SERVERS_AT_ONCE))
	@${TOUCH} ${TOUCH_FLAGS} ${SHARED_COOKIE}
.endif

post-install:
	@( \
	cd ${WRKDIR} ; ${TOUCH} ${TOUCH_FLAGS} ${INSTALL_COOKIE} ; \
		${TOUCH} ${TOUCH_FLAGS} `${BASENAME} ${INSTALL_COOKIE} .${SERVER}`.common )

post-package:
	@( \
	cd ${WRKDIR} ; 	${TOUCH} ${TOUCH_FLAGS} ${PACKAGE_COOKIE} )
.endif

.include <bsd.port.post.mk>
