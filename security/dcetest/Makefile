# Created by: Yonatan <onatan@gmail.com>
# $FreeBSD$

PORTNAME=	dcetest
PORTVERSION=	1.2
CATEGORIES=	security
MASTER_SITES=	PACKETSTORM/UNIX/scanners

MAINTAINER=	onatan@gmail.com
COMMENT=	Utility to dump MSRPC endpoint information from Windows systems

USES=	dos2unix
DOS2UNIX_GLOB=	*.c

ALL_TARGET=	dcetest
MAKE_ARGS=	CC="${CC}"
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/dcetest

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dcetest ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
