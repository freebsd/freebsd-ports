# Created by: nox@FreeBSD.org
# $FreeBSD$

PORTNAME=	linux_v4l2wrapper-kmod
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	LOCAL/nox \
		http://people.freebsd.org/~ae/
DISTNAME=	linux_v4l2_kld

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Linux compatibility layer - V4L2 ioctl handler

ONLY_FOR_ARCHS=	i386 amd64
PATCH_STRIP=	-p1
WRKSRC=		${WRKDIR}/linux_v4l2

# Remember to remove references to Makefile.sub in other ports...
DEPRECATED=	Included now in all supported FreeBSD versions
EXPIRATION_DATE=	2014-03-15

USES=		kmod tar:tgz

.include <bsd.port.pre.mk>

PLIST_FILES+=	"@cwd /"
PLIST_FILES+=	${KMODDIR:C,^/,,}/linux_v4l2wrapper.ko

CFLAGS+=	${DEBUG_FLAGS}

.include "${.CURDIR}/Makefile.sub"

.if ${LINUX_V4L2_AVAILABLE} == "1"
IGNORE=		is already in kernel
.endif

.include <bsd.port.post.mk>
