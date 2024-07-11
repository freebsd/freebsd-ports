PORTNAME=	nss
PORTVERSION=	3.90.0
DISTVERSIONSUFFIX=	-7.el9_4
PORTREVISION=	3
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Network Security Services (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://developer.mozilla.org/docs/Mozilla/Projects/NSS

USES=		cpe linux:rl9
CPE_VENDOR=	mozilla
USE_LDCONFIG=	yes
USE_LINUX=	nspr sqlite3
USE_LINUX_RPM=	yes

LIB_DISTNAMES=	${DISTNAME} \
		${PORTNAME}-softokn-${PORTVERSION}${DISTVERSIONSUFFIX} \
		${PORTNAME}-softokn-freebl-${PORTVERSION}${DISTVERSIONSUFFIX} \
		${PORTNAME}-util-${PORTVERSION}${DISTVERSIONSUFFIX}
SRC_DISTFILES=	${DISTNAME}${SRC_SUFX}:SOURCE

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
