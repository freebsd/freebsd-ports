# New ports collection makefile for:	cvsup
# Date created:		7 August 1996
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	cvsup
PORTVERSION?=	16.1h
PORTREVISION?=	2
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_FREEBSD_ORG}
MASTER_SITE_SUBDIR=development/CVSup/snapshots
DISTNAME=	cvsup-snap-${PORTVERSION}

MAINTAINER=	jdp@FreeBSD.org
COMMENT?=	General network file distribution system optimized for CVS (GUI version)

PROCESSOR!=	/usr/bin/uname -p
.if ${PROCESSOR} == "amd64"
USE_BZIP2=	yes
.endif

ONLY_FOR_ARCHS=	alpha amd64 i386 sparc64

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 410000
BROKEN=		Not supported on versions earlier than 4.1-RELEASE
.endif

.if ${ARCH} == "alpha"
TARGET=		FBSD_ALPHA
.elif ${ARCH} == "amd64"
PORTREVISION=	1
MASTER_SITE_SUBDIR=	obrien
MASTER_SITES=	${MASTER_SITE_LOCAL}
DISTNAME=	cvsup-without-gui.amd64
NO_WRKSUBDIR=	yes
USE_REINPLACE=	yes
NO_BUILD=	binary-only
.elif ${ARCH} == "i386"
TARGET=		FreeBSD4
.elif ${ARCH} == "sparc64"
TARGET=		FBSD_SPARC64
.endif

.ifdef WITHOUT_X11
M3FLAGS+=	-DNOGUI
.if ${ARCH} != "amd64"
BUILD_DEPENDS=	${PREFIX}/lib/m3/pkg/tcp/${TARGET}/libm3tcp.a:${PORTSDIR}/lang/ezm3
.endif		# != amd64
PKGNAMESUFFIX=	-without-gui
COMMENT=	General network file distribution system optimized for CVS (non-GUI version)
DESCR=		${PKGDIR}/pkg-descr.nogui
.else
.if ${ARCH} != "amd64"
USE_XLIB=	yes
BUILD_DEPENDS=	${PREFIX}/lib/m3/pkg/formsvbt/${TARGET}/libm3formsvbt.a:${PORTSDIR}/lang/ezm3
.endif		# != amd64
.endif

.if ${ARCH} != "amd64"
MAKE_ARGS+=	PREFIX=${PREFIX} M3FLAGS="${M3FLAGS}"
MAN1=		cvpasswd.1 cvsup.1
MAN8=		cvsupd.8
.endif		# != amd64

.ifdef STATIC
M3FLAGS+=	-DSTATIC
.endif

pre-fetch:
.ifndef WITHOUT_X11
	@${ECHO_MSG} "*****************************************************"
	@${ECHO_MSG} "* To build CVSup without X11 (and without the GUI), *"
	@${ECHO_MSG} "* use the \"net/cvsup-without-gui\" port.             *"
	@${ECHO_MSG} "*****************************************************"
.endif
	@${TRUE}

post-install:
	@${MKDIR} ${PREFIX}/share/cvsup
	@${INSTALL_DATA} ${WRKSRC}/License ${PREFIX}/share/cvsup/License

.if ${ARCH} == "amd64"
PROGS=	bin/cvsup sbin/cvsupd bin/cvpasswd

do-patch:
	@${TRUE}

do-configure:
	@${TOUCH} ${WRKSRC}/License
	@${TOUCH} ${TOUCH_FLAGS} ${CONFIGURE_COOKIE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cvsup-without-gui.amd64 ${PREFIX}/bin/cvsup
	@${ECHO} '#! /bin/sh'	> ${PREFIX}/sbin/cvsupd
	@${ECHO} 'echo `basename $$0` not supported on `uname -m`' \
		>> ${PREFIX}/sbin/cvsupd
	@${ECHO} '#! /bin/sh'	> ${PREFIX}/bin/cvpasswd
	@${ECHO} 'echo `basename $$0` not supported on `uname -m`' \
		>> ${PREFIX}/sbin/cvpasswd
	cd ${PREFIX} ; \
		${CHOWN} ${BINOWN}:${BINGRP} ${PROGS} ; \
		${CHMOD} ${BINMODE} ${PROGS}
.endif

.include <bsd.port.post.mk>
