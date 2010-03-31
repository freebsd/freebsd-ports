# New ports collection makefile for:	cvsup
# Date created:		7 August 1996
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	cvsup
PORTVERSION=	16.1h
PORTREVISION=	4
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_FREEBSD_ORG}
MASTER_SITE_SUBDIR=development/CVSup/snapshots
DISTNAME=	cvsup-snap-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	File distribution system optimized for CVS

ONLY_FOR_ARCHS=	alpha amd64 i386 sparc64

.if !defined(SLAVE_WITHOUT_GUI)
OPTIONS+=	X11 "Build with X11 support" on
.endif

.include <bsd.port.pre.mk>

.if defined(STATIC)
WITH_STATIC=	yes
.endif

.if defined(WITH_STATIC) && !defined(WITHOUT_STATIC)
M3FLAGS+=	-DSTATIC
.endif

.if ${ARCH} == "alpha"
TARGET=		FBSD_ALPHA
.elif ${ARCH} == "amd64"
MAINTAINER=	bzeeb+freebsdports@zabbadoz.net
TARGET=		FBSD_AMD64
AMD64_PATCHES=	p-amd64-aa p-amd64-zlib
.elif ${ARCH} == "i386"
TARGET=		FreeBSD4
.elif ${ARCH} == "sparc64"
TARGET=		FBSD_SPARC64
.endif

.if defined(WITHOUT_X11)
M3FLAGS+=	-DNOGUI
BUILD_DEPENDS=	${PREFIX}/lib/m3/pkg/tcp/${TARGET}/libm3tcp.a:${PORTSDIR}/lang/ezm3
PKGNAMESUFFIX=	-without-gui
COMMENT+=	(non-GUI version)
DESCR=		${PKGDIR}/pkg-descr.nogui
CONFLICTS=	cvsup-[0-9]*
.else
.if ${ARCH} == "amd64"
IGNORE=		does not support GUI on amd64, please disable X11 option or use net/cvsup-without-gui instead
.else
USE_XORG+=	oldx dmx pixman xaw 
COMMENT+=	(GUI version)
BUILD_DEPENDS=	${PREFIX}/lib/m3/pkg/formsvbt/${TARGET}/libm3formsvbt.a:${PORTSDIR}/lang/ezm3
CONFLICTS=	cvsup-without-gui-[0-9]*
.endif
.endif

MAKE_ARGS+=	PREFIX=${PREFIX} M3FLAGS="${M3FLAGS}"
MAN1=		cvpasswd.1 cvsup.1
MAN8=		cvsupd.8

pre-fetch:
.if !defined(WITHOUT_X11) && ${ARCH} == "amd64"
	@${ECHO_MSG} "*****************************************************"
	@${ECHO_MSG} "* CVSup with X11 is not yet supported on amd64.     *"
	@${ECHO_MSG} "* I will build cvsup without X11 support now.       *"
	@${ECHO_MSG} "*****************************************************"
.endif

pre-patch:
.if ${ARCH} == "amd64"
.for f in ${AMD64_PATCHES}
	@cd ${WRKSRC} && ${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/${f}
.endfor
.endif

post-install:
	@${MKDIR} ${PREFIX}/share/cvsup
	@${INSTALL_DATA} ${WRKSRC}/License ${PREFIX}/share/cvsup/License

.include <bsd.port.post.mk>
