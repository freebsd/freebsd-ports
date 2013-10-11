# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	e169-stats
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.mavetju.org/download/

MAINTAINER=	edwin@mavetju.org
COMMENT=	Curses realtime statistics for the Huawei E169 modem

PLIST_FILES=	bin/e169-stats

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/e169-stats ${PREFIX}/bin

.include <bsd.port.mk>
