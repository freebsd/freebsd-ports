PORTNAME=	wmmemload
DISTVERSION=	0.1.8
PORTREVISION=	2
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	https://dev.gentoo.org/~voyageur/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dockapp for monitoring memory and swap usage
WWW=		https://windowmaker.org/dockapps/?name=wmmemload

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf xorg
USE_XORG=	x11 xext xpm
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/dockapps

.include <bsd.port.mk>
