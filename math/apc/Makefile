# Created by: Eric A. Griff <eagriff@global2000.net>
# $FreeBSD$

PORTNAME=	apc
PORTVERSION=	1.0
PORTREVISION=	8
CATEGORIES=	math
MASTER_SITES=	LOCAL/arved

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Xforms based Auto Payment Calculator

LICENSE=	GPLv2

LIB_DEPENDS=	libforms.so:x11-toolkits/xforms

USE_XORG=	x11 xpm
PLIST_FILES=	bin/apc man/man1/apc.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/apc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/apc.1 ${STAGEDIR}/${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
