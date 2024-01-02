PORTNAME=	linux_dvbwrapper-kmod
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	multimedia
DISTFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Linux compatibility layer - DVB ioctl handler
WWW=		https://people.freebsd.org/~nox/dvb/

ONLY_FOR_ARCHS=	aarch64 amd64 i386

USES=		kmod uidfix

PLIST_FILES=	${KMODDIR}/linux_dvbwrapper.ko

CFLAGS+=	${DEBUG_FLAGS}

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${FILESDIR}/Makefile ${FILESDIR}/*.[ch] ${WRKSRC}

.include <bsd.port.mk>
