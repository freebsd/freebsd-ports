# New ports collection makefile for:   hammerhead
# Date created:        14 November 2002
# Whom:                John von Essen
#
# $FreeBSD$
#

PORTNAME=	hammerhead
PORTVERSION=	2.1.4
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	A webserver stressing tool

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' \
		${WRKSRC}/src/Makefile

MAN1=	hammerhead.1

.include <bsd.port.mk>
