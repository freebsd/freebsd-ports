# New ports collection makefile for:	cvsup
# Date created:		7 August 1996
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	cvsup
PORTVERSION?=	16.1h
PORTREVISION?=	0
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_FREEBSD_ORG}
MASTER_SITE_SUBDIR=development/CVSup/snapshots
DISTNAME=	cvsup-snap-${PORTVERSION}

MAINTAINER=	jdp@FreeBSD.org
COMMENT?=	General network file distribution system optimized for CVS (GUI version)

.ifdef WITHOUT_X11
M3FLAGS+=	-DNOGUI
BUILD_DEPENDS=	${PREFIX}/lib/m3/pkg/tcp/${TARGET}/libm3tcp.a:${PORTSDIR}/lang/ezm3
PKGNAMESUFFIX=	-without-gui
COMMENT=	General network file distribution system optimized for CVS (non-GUI version)
DESCR=		${PKGDIR}/pkg-descr.nogui
.else
USE_XLIB=	yes
BUILD_DEPENDS=	${PREFIX}/lib/m3/pkg/formsvbt/${TARGET}/libm3formsvbt.a:${PORTSDIR}/lang/ezm3
.endif

MAKE_ARGS+=	PREFIX=${PREFIX} M3FLAGS="${M3FLAGS}"
MAN1=		cvpasswd.1 cvsup.1
MAN8=		cvsupd.8

.ifdef STATIC
M3FLAGS+=	-DSTATIC
.endif

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS=	alpha i386 sparc64

.if ${OSVERSION} < 410000
BROKEN=		Not supported on versions earlier than 4.1-RELEASE
.endif

.if ${ARCH} == "alpha"
TARGET=		FBSD_ALPHA
.elif ${ARCH} == "i386"
TARGET=		FreeBSD4
.elif ${ARCH} == "sparc64"
TARGET=		FBSD_SPARC64
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

.include <bsd.port.post.mk>
