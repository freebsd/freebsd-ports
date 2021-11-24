# Created by: Yonatan <onatan@gmail.com>

PORTNAME=	dcetest
PORTVERSION=	1.2
CATEGORIES=	security
MASTER_SITES=	PACKETSTORM/UNIX/scanners

MAINTAINER=	onatan@gmail.com
COMMENT=	Utility to dump MSRPC endpoint information from Windows systems

DEPRECATED=	Targets deprecated protocol by Microsoft in favour of .NET
EXPIRATION_DATE=2022-03-31

USES=	dos2unix
DOS2UNIX_GLOB=	*.c

ALL_TARGET=	dcetest
MAKE_ARGS=	CC="${CC}"
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/dcetest

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dcetest ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
