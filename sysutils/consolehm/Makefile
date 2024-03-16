PORTNAME=	consolehm
PORTVERSION=	1.31
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/fenner

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Console based hardware monitor for FreeBSD

BROKEN_aarch64=	fails to build: fatal error: 'machine/pio.h' file not found

USES=		uidfix
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/consolehm/consolehm
MAKE_ARGS=	PREFIX="${PREFIX}" \
		MANDIR="${PREFIX}/share/man/man"
MAKE_ENV=	ARCH=${ARCH}

PLIST_FILES=	bin/chm share/man/man8/chm.8.gz

.include <bsd.port.mk>
