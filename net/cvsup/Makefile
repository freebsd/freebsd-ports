# Created by: asami
# $FreeBSD$

PORTNAME=	cvsup
PORTVERSION=	16.1h
PORTREVISION=	6
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_FREEBSD_ORG}
MASTER_SITE_SUBDIR=development/CVSup/snapshots
DISTNAME=	cvsup-snap-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	File distribution system optimized for CVS

ONLY_FOR_ARCHS=	amd64 i386 sparc64

OPTIONS_DEFINE=	X11 STATIC
OPTIONS_DEFAULT=	X11

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSTATIC}
WITH_STATIC=	yes
M3FLAGS+=	-DSTATIC
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
TARGET=		FBSD_AMD64
AMD64_PATCHES=	p-amd64-aa p-amd64-zlib
.elif ${ARCH} == "i386"
TARGET=		FreeBSD4
.elif ${ARCH} == "sparc64"
TARGET=		FBSD_SPARC64
.endif

.if ! ${PORT_OPTIONS:MX11}
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
