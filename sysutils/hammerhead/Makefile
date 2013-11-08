# Created by: John von Essen
# $FreeBSD$

PORTNAME=	hammerhead
PORTVERSION=	2.1.4
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	A webserver stressing tool

DEPRECATED=	Development no more active
EXPIRATION_DATE=	2013-12-08

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' \
		${WRKSRC}/src/Makefile

MAN1=	hammerhead.1

.include <bsd.port.mk>
