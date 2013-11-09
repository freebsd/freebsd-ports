# Created by: nox@FreeBSD.org
# $FreeBSD$

PORTNAME=	linux_dvbwrapper-kmod
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	multimedia
DISTFILES=	# none

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Linux compatibility layer - DVB ioctl handler

ONLY_FOR_ARCHS=	i386 amd64

NO_STAGE=	yes

USES=		kmod
.include <bsd.port.pre.mk>

PLIST_FILES+=	"@cwd /"
PLIST_FILES+=	${KMODDIR:C,^/,,}/linux_dvbwrapper.ko

CFLAGS+=	${DEBUG_FLAGS}

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${FILESDIR}/Makefile ${FILESDIR}/*.[ch] ${WRKSRC}

.include <bsd.port.post.mk>
