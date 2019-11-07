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

WRKSRC=		${WRKDIR}/wmtime.app/wmtime
USES=		imake xorg
USE_XORG=	xpm
USE_CSTD=	gnu89

PLIST_FILES=	bin/wmtime

post-extract:
	${CP} ${WRKSRC}/../Imakefile ${WRKSRC}/Imakefile

.include <bsd.port.mk>
