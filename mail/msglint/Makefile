# $FreeBSD$

PORTNAME=	msglint
PORTVERSION=	1.04
CATEGORIES=	mail
MASTER_SITES=	https://tools.ietf.org/tools/msglint/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	RFC 822/MIME/DSN/MDN/Tracking-Status message validator

LICENSE_NAME=	Chris-Newman
LICENSE_PERMS=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell
LICENSE_FILE=	LICENSE

NO_WRKSUBDIR=	yes
ALL_TARGET=	msglint
PLIST_FILES=	bin/msglint

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
