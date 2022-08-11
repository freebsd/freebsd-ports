PORTNAME=	wmflame
PORTVERSION=	0.60
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	AFTERSTEP/stable/rpms/misc-tarballs \
		http://web.novalis.org/programs/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dockapp that shows the load average as a flame

LICENSE=	GPLv2

BROKEN_FreeBSD_13=	ld: error: duplicate symbol: Root
BROKEN_FreeBSD_14=	ld: error: duplicate symbol: Root

USES=		gmake xorg
USE_XORG=	x11 xpm

PLIST_FILES=	bin/wmflame

WRKSRC=		${WRKDIR}/wmflame.app/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmflame ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
