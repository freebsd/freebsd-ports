PORTNAME=	sensors
DISTVERSION=	0.6
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/vermaden/sensors/raw/master/release/:source \
		https://github.com/vermaden/sensors/raw/master/:license
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:source \
		LICENSE:license
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	vermaden@interia.pl
COMMENT=	Show sensors and temperaturs on FreeBSD UNIX system
WWW=		https://github.com/vermaden/sensors

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

NO_ARCH=	YES
NO_BUILD=	YES

PLIST_FILES=	sbin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sensors \
	${STAGEDIR}${PREFIX}/sbin/${PORTNAME}

.include <bsd.port.mk>
