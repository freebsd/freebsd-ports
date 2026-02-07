PORTNAME=	pdixtract
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/markus
DISTNAME=	PDITOOL

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extracts or converts .pdi file sets to .iso

LICENSE=	GPLv2

NO_WRKSUBDIR=	yes
USES=		zip

PLIST_FILES=	bin/pdixtract

do-build:
	cd ${WRKSRC}; ${CC} ${CFLAGS} pdixtract.c -o pdixtract

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pdixtract ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
