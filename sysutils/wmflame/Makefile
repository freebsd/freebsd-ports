# New ports collection makefile for:	wmflame
# Date created:				16 May 2002
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	wmflame
PORTVERSION=	0.60
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://web.novalis.org/programs/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A dockapp that shows the load average as a flame

PLIST_FILES=	bin/wmflame
WRKSRC=	${WRKDIR}/wmflame.app/${PORTNAME}
USE_GMAKE=	yes
USE_XPM=	yes
USE_X_PREFIX=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmflame ${PREFIX}/bin

.include <bsd.port.mk>
