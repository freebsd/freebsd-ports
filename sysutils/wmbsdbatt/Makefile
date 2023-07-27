PORTNAME=	wmbsdbatt
PORTVERSION=	0.1
PORTREVISION=	5
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://freebsd.nsu.ru/distfiles/ LOCAL/danfe \
		http://mirror.its.dal.ca/freebsd/distfiles/ \
		http://vault.101011010.xyz/distfiles/ \
		https://discovery.midnightbsd.org/mports/distfiles/

MAINTAINER=	xride@FreeBSD.org
COMMENT=	Dockapp for battery and temperature monitoring via ACPI
WWW=		http://mailbox.univie.ac.at/~le/wmbsdbatt/

LICENSE=	GPLv2+

USES=		xorg
USE_XORG=	x11 xext xpm

PLIST_FILES=	bin/wmbsdbatt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmbsdbatt ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
