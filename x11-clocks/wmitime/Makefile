PORTNAME=	wmitime
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	x11-clocks windowmaker
MASTER_SITES=	https://www.dockapps.net/download/

MAINTAINER=	khorben@defora.org
COMMENT=	Docking clock app also showing the new Internet time
WWW=		https://www.dockapps.net/wmitime

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdockapp.so:x11-wm/libdockapp

USES=		gmake iconv localbase:ldflags xorg
USE_XORG=	x11 xext xpm

MAKE_ARGS=	CFLAGS="-O2 -Wall ${CFLAGS}" \
		MANDIR="${PREFIX}/share/man/man1"
ALL_TARGET=	wmitime

WRKSRC=		${WRKDIR}/dockapps-26db447

.include <bsd.port.mk>
