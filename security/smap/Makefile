# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	smap
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	security net
MASTER_SITES=	http://www.wormulon.net/smap/

MAINTAINER=	edwin@mavetju.org
COMMENT=	SIP scanner and identifier

PLIST_FILES=	bin/smap share/smap/fingerprint.db
PLIST_DIRS=	share/smap

USE_GMAKE=	yes

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/smap ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/smap
	${INSTALL_DATA} ${WRKSRC}/fingerprint.db ${PREFIX}/share/smap

.include <bsd.port.mk>
