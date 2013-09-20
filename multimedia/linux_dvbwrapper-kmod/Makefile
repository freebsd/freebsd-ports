# Created by: nox@FreeBSD.org
# $FreeBSD$

PORTNAME=	linux_dvbwrapper-kmod
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	multimedia kld
DISTFILES=	# none

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Linux compatibility layer - DVB ioctl handler

SSP_UNSAFE=	kernel module does not support ssp
ONLY_FOR_ARCHS=	i386 amd64

.include <bsd.port.pre.mk>

PLIST_FILES+=	"@cwd /"
PLIST_FILES+=	${KMODDIR:C,^/,,}/linux_dvbwrapper.ko
PLIST_FILES+=	"@exec kldxref ${KMODDIR}"
PLIST_FILES+=	"@unexec kldxref ${KMODDIR}"

# install where x11/nvidia-driver does also:
KMODDIR=	/boot/modules

MAKE_ENV+=	KMODDIR="${KMODDIR}"

SYSDIR?=	${SRC_BASE}/sys
MAKE_ENV+=	SYSDIR="${SYSDIR}"

CFLAGS+=	${DEBUG_FLAGS}

.if !exists(${SYSDIR}/Makefile)
IGNORE=		requires kernel source to be installed
.endif

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${FILESDIR}/Makefile ${FILESDIR}/*.[ch] ${WRKSRC}

.include <bsd.port.post.mk>
