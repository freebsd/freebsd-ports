# New ports collection makefile for:	cvsup
# Date created:		7 August 1996
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	cvsup
PORTVERSION?=	16.1e
PORTREVISION?=	0
CATEGORIES=	net devel
MASTER_SITES=	http://people.freebsd.org/~jdp/s1g/ \
		ftp://ftp3.freebsd.org/pub/FreeBSD/development/CVSup/snapshots/ \
		ftp://ftp.freebsd.org/pub/FreeBSD/development/CVSup/snapshots/ \
		ftp://ftp.cs.tu-berlin.de/pub/FreeBSD/development/CVSup/snapshots/
DISTNAME=	cvsup-snap-${PORTVERSION}

MAINTAINER=	jdp@FreeBSD.org

.ifdef PACKAGE_BUILDING
STATIC=		yes
.endif

.ifdef WITHOUT_X11
M3FLAGS+=	-DNOGUI
BUILD_DEPENDS=	${L1}libm3tcp${L2}:${PORTSDIR}/lang/pm3-net
.ifndef STATIC
RUN_DEPENDS=	${L1}libm3tcp${L2}:${PORTSDIR}/lang/pm3-net
.endif
.else
BUILD_DEPENDS=	${L1}libm3formsvbt${L2}:${PORTSDIR}/lang/pm3-forms
.ifndef STATIC
RUN_DEPENDS=	${L1}libm3formsvbt${L2}:${PORTSDIR}/lang/pm3-forms
.endif
.endif

MAKE_ARGS+=	PREFIX=${PREFIX} M3FLAGS="${M3FLAGS}"
MAN1=		cvpasswd.1 cvsup.1
MAN8=		cvsupd.8

L1=		${PREFIX}/lib/m3/${TARGET}/
SOVERSION=	7

.ifdef STATIC
M3FLAGS+=	-DSTATIC
.endif

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "aout"
L2=		.so.${SOVERSION}.0
TARGET=		FreeBSD2
TARGETDIR=	freebsd-2
WORDSIZE=	32
.elif ${ARCH} == "i386"
L2=		.so.${SOVERSION}
.if ${OSVERSION} < 400011
TARGET=		FreeBSD3
TARGETDIR=	freebsd-3
.else
TARGET=		FreeBSD4
TARGETDIR=	freebsd-4
.endif
WORDSIZE=	32
.elif ${ARCH} == "alpha"
.if ${OSVERSION} < 400011
BROKEN=		Not supported on older versions of FreeBSD/Alpha
.endif
CFLAGS+=	-mieee
L2=		.so.${SOVERSION}
TARGET=		FBSD_ALPHA
TARGETDIR=	fbsd-alpha
WORDSIZE=	64
.endif

pre-fetch:
.if empty(TARGET)
	@${ECHO_MSG} "Cannot determine M3 target for this architecture"
	@${FALSE}
.endif
.ifndef WITHOUT_X11
	@${ECHO_MSG} -n "To build this port without X11 (and without the GUI),"
	@${ECHO_MSG} " define \"WITHOUT_X11\"."
.endif
	@${TRUE}

post-install:
	@${MKDIR} ${PREFIX}/share/cvsup
	@${INSTALL_DATA} ${WRKSRC}/License ${PREFIX}/share/cvsup/License

.include <bsd.port.post.mk>
