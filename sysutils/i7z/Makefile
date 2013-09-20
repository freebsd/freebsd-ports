# $FreeBSD$

PORTNAME=	i7z
PORTVERSION=	0.27.2
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	zont@FreeBSD.org
COMMENT=	Thermal and C-state reporting utility for Intel-Core-i CPUs

LICENSE=	GPLv2

USE_GMAKE=	yes

MAN1=		i7z.1
PLIST_FILES=	bin/i7z

ONLY_FOR_ARCHS=	i386 amd64

# Disable scheduling flags as they cause segfaults since they are enabled at
# default FreeBSD optimization levels (-O2, -O3, -Os)
CFLAGS+=	-fno-schedule-insns2 -fno-schedule-insns -fno-caller-saves

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.man \
		${MANPREFIX}/man/man1/${MAN1}

.include <bsd.port.mk>
