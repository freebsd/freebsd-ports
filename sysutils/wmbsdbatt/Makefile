PORTNAME=	wmbsdbatt
PORTVERSION=	0.1
PORTREVISION=	5
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://mirror.its.dal.ca/freebsd/distfiles/	\
		https://discovery.midnightbsd.org/mports/distfiles/

MAINTAINER=	xride@FreeBSD.org
COMMENT=	Dockapp for battery & temperature monitoring through ACPI

LICENSE=	GPLv2

USES=		xorg
USE_XORG=	x11 xpm

PLIST_FILES=	bin/wmbsdbatt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmbsdbatt ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
