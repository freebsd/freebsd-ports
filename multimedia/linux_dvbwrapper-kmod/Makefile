# Created by: nox@FreeBSD.org
# $FreeBSD$

PORTNAME=	linux_dvbwrapper-kmod
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	multimedia
DISTFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Linux compatibility layer - DVB ioctl handler

ONLY_FOR_ARCHS=	i386 amd64

USES=		kmod uidfix

PLIST_FILES=	${KMODDIR}/linux_dvbwrapper.ko

CFLAGS+=	${DEBUG_FLAGS}

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${FILESDIR}/Makefile ${FILESDIR}/*.[ch] ${WRKSRC}

.include <bsd.port.mk>
