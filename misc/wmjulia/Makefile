# New ports collection makefile for:	wmjulia
# Date created:				16 May 2002
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	wmjulia
PORTVERSION=	0.40
PORTREVISION=	1
CATEGORIES=	misc windowmaker afterstep
MASTER_SITES=	http://web.novalis.org/programs/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A dockapp that creates an animated Julia set

WRKSRC=	${WRKDIR}/${PORTNAME}.app/${PORTNAME}
USE_GMAKE=	yes
USE_XPM=	yes
USE_X_PREFIX=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
