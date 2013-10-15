# $FreeBSD$

PORTNAME=	i7z
PORTVERSION=	0.27.2
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	zont@FreeBSD.org
COMMENT=	Thermal and C-state reporting utility for Intel-Core-i CPUs

LICENSE=	GPLv2

USES=		gmake

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

ONLY_FOR_ARCHS=	i386 amd64

# Disable scheduling flags as they cause segfaults since they are enabled at
# default FreeBSD optimization levels (-O2, -O3, -Os)
CFLAGS+=	-fno-schedule-insns2 -fno-schedule-insns -fno-caller-saves

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.man \
		${STAGEDIR}${MANPREFIX}/man/man1/${PORTNAME}.1

.include <bsd.port.mk>
