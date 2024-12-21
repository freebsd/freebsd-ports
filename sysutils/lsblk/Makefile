PORTNAME=	lsblk
DISTVERSION=	3.9
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/vermaden/lsblk/raw/master/release/:source \
		https://github.com/vermaden/lsblk/raw/master/:license
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:source \
		LICENSE:license
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	vermaden@interia.pl
COMMENT=	Lists information about block devices in the system
WWW=		https://github.com/vermaden/lsblk

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

NO_ARCH=	YES
NO_BUILD=	YES

PLIST_FILES=	sbin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/lsblk.sh \
	${STAGEDIR}${PREFIX}/sbin/${PORTNAME}

.include <bsd.port.mk>
