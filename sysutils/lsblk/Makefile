PORTNAME=	lsblk
PORTVERSION=	3.5
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/vermaden/lsblk/raw/master/release/

MAINTAINER=	vermaden@interia.pl
COMMENT=	Lists information about block devices in the system

LICENSE=	BSD2CLAUSE

NO_ARCH=	YES
NO_BUILD=	YES

PLIST_FILES=	sbin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/lsblk.sh \
	${STAGEDIR}${PREFIX}/sbin/${PORTNAME}

.include <bsd.port.mk>

