# Created by: Rich Neswold <rneswold@mcs.net>
# $FreeBSD$

PORTNAME=	wmtime
PORTVERSION=	1.0b2
PORTREVISION=	1
CATEGORIES=	x11-clocks windowmaker
MASTER_SITES=	http://web.cs.mun.ca/~gstarkes/wmaker/dockapps/files/ \
		http://freebsd.unixfreunde.de/sources/ \
		http://mirror2.unixfreunde.de/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Time/Date applet for WindowMaker

PLIST_FILES=	bin/wmtime
WRKSRC=		${WRKDIR}/wmtime.app/wmtime
USES=		imake
USE_XORG=	xpm

post-extract:
	${CP} ${WRKSRC}/../Imakefile ${WRKSRC}/Imakefile

.include <bsd.port.mk>
