# New ports collection makefile for:	cvsup
# Date created:		7 August 1996
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	cvsup
PORTVERSION?=	16.1f
PORTREVISION?=	0
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_FREEBSD_ORG}
MASTER_SITE_SUBDIR=development/CVSup/snapshots
DISTNAME=	cvsup-snap-${PORTVERSION}

MAINTAINER=	jdp@FreeBSD.org

.ifdef WITHOUT_X11
M3FLAGS+=	-DNOGUI
BUILD_DEPENDS=	${PREFIX}/lib/m3/pkg/tcp/${TARGET}/libm3tcp.a:${PORTSDIR}/lang/ezm3
PKGNAMESUFFIX=	-without-gui
COMMENT=	${PKGDIR}/pkg-comment.nogui
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

.if ${PORTOBJFORMAT} == "aout"
TARGET=		FreeBSD2
.elif ${ARCH} == "i386"
.if ${OSVERSION} < 400011
TARGET=		FreeBSD3
.else
TARGET=		FreeBSD4
.endif
.elif ${ARCH} == "alpha"
.if ${OSVERSION} < 400011
BROKEN=		Not supported on older versions of FreeBSD/Alpha
.endif
TARGET=		FBSD_ALPHA
.endif

pre-fetch:
.if empty(TARGET)
	@${ECHO_MSG} "Cannot determine M3 target for this architecture"
	@${FALSE}
.endif
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
