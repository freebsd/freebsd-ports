# Created by: sumikawa

PORTNAME=	xbattbar
PORTVERSION=	1.4.2
PORTREVISION=	8
CATEGORIES=	sysutils
MASTER_SITES=	http://ftp.corbina.net/gentoo-distfiles/d6/	\
		https://ftp.fau.de/gentoo/distfiles/		\
		https://mirrors.mit.edu/gentoo-distfiles/distfiles/d6/

DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple battery meter

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		imake xorg
USE_XORG=	x11 xext
WRKSRC=		${WRKDIR}/xbattbar-${PORTVERSION}
PLIST_FILES=	bin/xbattbar \
		man/man1/xbattbar.1.gz

.include <bsd.port.mk>
