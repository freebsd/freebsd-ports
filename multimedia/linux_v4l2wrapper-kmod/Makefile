# New ports collection makefile for:	linux_v4l2wrapper-kmod
# Date created:				Fri May  6 22:30:00 CEST 2011
# Whom:					nox@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	linux_v4l2wrapper-kmod
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	multimedia kld
MASTER_SITES=	LOCAL/nox \
		http://people.freebsd.org/~ae/
DISTNAME=	linux_v4l2_kld
EXTRACT_SUFX=	.tgz

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Linux compatibility layer - V4L2 ioctl handler

ONLY_FOR_ARCHS=	i386 amd64
PATCH_STRIP=	-p1
WRKSRC=		${WRKDIR}/linux_v4l2

.include <bsd.port.pre.mk>

PLIST_FILES+=	"@cwd /"
PLIST_FILES+=	${KMODDIR:C,^/,,}/linux_v4l2wrapper.ko
PLIST_FILES+=	"@exec kldxref ${KMODDIR}"
PLIST_FILES+=	"@unexec kldxref ${KMODDIR}"

# install where x11/nvidia-driver does also:
KMODDIR=	/boot/modules

MAKE_ENV+=	KMODDIR="${KMODDIR}"

SYSDIR?=	${SRC_BASE}/sys
MAKE_ENV+=	SYSDIR="${SYSDIR}"

CFLAGS+=	${DEBUG_FLAGS}

# try to avoid child processes when finding out if already in the kernel
.if ${OSVERSION} > 900036 || (${OSVERSION} < 900000 && ${OSVERSION} > 802508)
INBASE=		1
.else
.if ${OSVERSION} == 900036 || ${OSVERSION} == 802508
INBASE!=	($(SYSCTL) -n kern.features.linuxulator_v4l2 2>/dev/null || true)
.else
INBASE=		0
.endif
.endif

.if ${INBASE} == "1"
IGNORE=		is already in kernel
.else
.if !exists(${SYSDIR}/Makefile)
IGNORE=		requires kernel source to be installed
.endif
.endif

.include <bsd.port.post.mk>
