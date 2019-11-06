# Created by: dchapes@zeus.leitch.com
# $FreeBSD$

PORTNAME=	xbuffy
PORTVERSION=	3.3.3
PORTREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	http://www.fiction.net/blong/programs/xbuffy/
DISTNAME=	${PORTNAME}-3.3.bl.3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Replacement for xbiff that handles multiple mail files

USES=		cpe gmake xorg
USE_XORG=	xext xt xaw
CPE_VENDOR=	xbuffy_project
GNU_CONFIGURE=	yes
PLIST_FILES=	bin/xbuffy lib/X11/app-defaults/XBuffy man/man1/xbuffy.1.gz

post-build:
	${STRIP_CMD} ${WRKSRC}/${PORTNAME}

.include <bsd.port.mk>
