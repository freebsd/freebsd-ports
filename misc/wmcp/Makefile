# New ports collection makefile for:	wmcp
# Version required:		1.2.8
# Date created:			10 February 1999
# Whom:				Jim Mock <jim@phrantic.phear.net>
#
# $Id: Makefile,v 1.2 1999/05/09 16:56:14 steve Exp $
#

DISTNAME=	wmcp-1.2.8
CATEGORIES=	misc windowmaker
MASTER_SITES=	http://users.linuxbox.com/~bac/src/wmcp/

MAINTAINER=	jim@phrantic.phear.net

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_GMAKE=	yes
USE_X_PREFIX=	yes

pre-build:
	(cd ${WRKSRC} && ${GMAKE} clean)

do-build:
	(cd ${WRKSRC} && ${GMAKE})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmcp ${PREFIX}/bin

.include <bsd.port.mk>
