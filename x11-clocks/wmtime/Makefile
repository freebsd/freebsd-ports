# New ports collection makefile for:   wmtime
# Date created:        1 July 1998
# Whom:                Rich Neswold <rneswold@mcs.net>
#
# $FreeBSD$
#

PORTNAME=	wmtime
PORTVERSION=	1.0b2
CATEGORIES=	x11-clocks windowmaker
MASTER_SITES=	ftp://ftp.enteract.com/users/rneswold/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Time/Date applet for WindowMaker

PLIST_FILES=	bin/wmtime
WRKSRC=		${WRKDIR}/wmtime.app/wmtime
USE_IMAKE=	yes
USE_XPM=	yes

post-extract:
	${CP} ${WRKSRC}/../Imakefile ${WRKSRC}/Imakefile

.include <bsd.port.mk>
