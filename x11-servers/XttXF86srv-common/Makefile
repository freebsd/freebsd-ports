# New ports collection makefile for:	Common Files for Xservers with Xtt
# Version required:	0.6
# Date created:		15 April 1998
# Whom:			Taguchi Takeshi <taguchi@tohoku.iij.ad.jp>
#
# $Id:$
#

DISTNAME=	xc
PKGNAME?=	xtt-xf86srv-common-0.6
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.xfree86.org/pub/XFree86/3.3.2/source/ \
		ftp://xfree86.cdrom.com/pub/XFree86/3.3.2/source/ \
		http://cclub.cc.tut.ac.jp/~go/unix/
DISTFILES=	X332src-1.tgz xtt06.tgz
.if !defined(XDM_DES) && defined(USA_RESIDENT)
.if ${USA_RESIDENT} == NO
MASTER_SITES+=	ftp://psych.psy.uq.oz.au/pub/X11R5/ \
		ftp://ftp.internat.freebsd.org/pub/FreeBSD/X11-Crypto/ \
		ftp://ftp3.za.freebsd.org/pub/FreeBSD/X11-Crypto/
DISTFILES+=	Wraphelp.c
EXTRACT_ONLY=	X332src-1.tgz xtt06.tgz
IGNOREFILES=	Wraphelp.c
.endif
.endif

MAINTAINER=	taguchi@tohoku.iij.ad.jp

LIB_DEPENDS=	ttf\\.2\\.:${PORTSDIR}/print/freetype
.if defined(SERVER)
RUN_DEPENDS=	${PREFIX}/lib/libfont.so.1.0:${.CURDIR}/../XttXF86srv-common
.endif

USE_X11=	yes
WRKDIR=		${.CURDIR}/../XttXF86srv-common/work
WRKSRC=		${WRKDIR}/xc
PATCHDIR=	${.CURDIR}/../XttXF86srv-common/patches
FILESDIR=	${.CURDIR}/../XttXF86srv-common/files
DIST_SUBDIR=	xc
.if defined(PATCH_DEBUG)
PATCH_XTT_ARGS= -d ${WRKDIR} -E ${PATCH_STRIP}
.else
PATCH_XTT_ARGS= -d ${WRKDIR} --forward --quiet -E ${PATCH_STRIP}
.endif
ALL_SERVER=	XF86_8514 XF86_AGX XF86_I128 XF86_Mach32 XF86_Mach64 \
		XF86_Mach8 XF86_Mono XF86_P9000 XF86_S3 \
		XF86_SVGA XF86_VGA16 XF86_W32
HOSTDEFSRC=	${FILESDIR}/host.def.template
HOSTDEFLOCAL=	${WRKDIR}/host.def.local
.if defined(SERVER) && (${SERVER} == xfs)
ALL_TARGET=	xfs
HOSTDEFSRV=	${FILESDIR}/host.def.xfs
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
DOCDIR=		${PREFIX}/lib/X11/doc/Xtt
BINOWN=		root
BINGRP=		wheel
XARGS?=		/usr/bin/xargs
DIRNAME?=	/usr/bin/dirname
TAIL?=		/usr/bin/tail

.if defined(SERVER)
CONFIGURECOOKIE=	${WRKDIR}/.configure_done
BUILDCOOKIE=		${WRKDIR}/.build_done
INSTALLCOOKIE=		${WRKDIR}/.install_done
CONFIGURE_COOKIE=	${WRKDIR}/.configure_done.${SERVER}
BUILD_COOKIE=		${WRKDIR}/.build_done.${SERVER}
INSTALL_COOKIE=		${WRKDIR}/.install_done.${SERVER}
PACKAGE_COOKIE=		${WRKDIR}/.package_done.${SERVER}
.else
PACKAGE_COOKIE=		${WRKDIR}/.package_done.common
.endif

.if !defined(SERVER) && !exists(${WRKDIR}/.build_done)
BROKEN=		This port is dummy.
.endif

.if defined(SERVER)
.if ${SERVER} != xfs
pre-fetch:
	@( \
	${ECHO} "*******" ; \
	${ECHO} "NOTICE:" ; \
	${ECHO} "*******" ; \
	${ECHO} " If you want to build/install this ${SERVER} server only," ; \
	${ECHO} "you should execute:" ; \
	${ECHO} "  # make THIS_SERVER_ONLY=YES" ; \
	${ECHO} "If the THIS_SERVER_ONLY flag not be set, this port will" ; \
	${ECHO} "build ALL Xtt-X servers, and install only ${SERVER}." ; \
	${ECHO} "This means you will need more disk space and CPU times." ; \
	${ECHO} "" ; \
 	)
.endif
.endif

pre-patch:
	@( \
	for i in ${WRKDIR}/xtt06/xtt06-serveronly.diff \
		${WRKDIR}/xtt06/xtt06-fs.diff; do \
	  ${PATCH} ${PATCH_XTT_ARGS} < $$i; \
	done ; \
	${CP} ${FILESDIR}/Imakefile ${WRKDIR} ; \
	(cd ${WRKDIR} ; ${XMKMF} ; ${SETENV} DISTDIR=${DISTDIR} WRKDIR=${WRKDIR} FILESDIR=${FILESDIR} ${MAKE}) ; \
	)

pre-configure:
	@( \
	FREETYPELIBDIR=`${LDCONFIG} -r | ${GREP} -e "-lttf" | ${AWK} '{print $$3}' | ${TAIL} -1 | ${XARGS} ${DIRNAME}` ; \
	FREETYPEINCDIR=`${DIRNAME} $$FREETYPELIBDIR`/include ; \
	${SED} "s+@FREETYPELIBDIR@+$$FREETYPELIBDIR+g" ${HOSTDEFSRC} | ${SED} "s+@FREETYPEINCDIR@+$$FREETYPEINCDIR+g" > ${HOSTDEFDST} ; \
	${CAT} ${HOSTDEFSRV} >> ${HOSTDEFDST} ; \
	if [ -f ${HOSTDEFLOCAL} ]; then \
		${CAT} ${HOSTDEFLOCAL} >> ${HOSTDEFDST} ; \
	fi; \
	)

.if defined(SERVER)
.if (defined(THIS_SERVER_ONLY) && ${THIS_SERVER_ONLY} == YES) || ${SERVER} == xfs
post-configure:
	@${TOUCH} ${TOUCH_FLAGS} ${CONFIGURE_COOKIE}

post-build:
	@${TOUCH} ${TOUCH_FLAGS} ${BUILD_COOKIE}
.else
post-configure:
	@ ( \
	for i in ${ALL_SERVER} ; do \
		${TOUCH} ${TOUCH_FLAGS} ${CONFIGURECOOKIE}.$${i} ; \
	done )

post-build:
	@ ( \
	for i in ${ALL_SERVER} ; do \
		${TOUCH} ${TOUCH_FLAGS} ${BUILDCOOKIE}.$${i} ; \
	done )
.endif
.endif

.if !defined(SERVER)
do-install:
	@( \
	${INSTALL_SCRIPT} ${FILESDIR}/mkfontdir.pl ${PREFIX}/bin; \
	${INSTALL_DATA} ${WRKSRC}/lib/font/libfont.so.* ${PREFIX}/lib; \
	${LDCONFIG} -m ${PREFIX}/lib; \
	${MKDIR} ${DOCDIR}; \
	${INSTALL_DATA} ${WRKDIR}/xtt06/xtt06-readme.jis ${DOCDIR}; \
	${INSTALL_DATA} ${WRKDIR}/xtt06/xtt06-example.jis ${DOCDIR} \
	)
.elif defined(SERVER) && ${SERVER} == xfs
do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/programs/xfs/xfs ${PREFIX}/bin/xfs.xtt
.else
do-install:
	@( \
	${INSTALL_PROGRAM} ${WRKSRC}/programs/Xserver/${SERVER} ${PREFIX}/bin/${SERVER}.xtt; \
	${LN} -fs ${PREFIX}/bin/${SERVER}.xtt ${PREFIX}/bin/X \
	)
.endif

post-install:
	@${TOUCH} ${TOUCH_FLAGS} ${INSTALL_COOKIE}

post-package:
	@${TOUCH} ${TOUCH_FLAGS} ${PACKAGE_COOKIE}

.include <bsd.port.mk>
