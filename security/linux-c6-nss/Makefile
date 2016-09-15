# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	nss
PORTVERSION=	3.21.0
PORTREVISION=	3
CATEGORIES=	security linux
LIB_DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		nss-util-${PORTVERSION}-2.el6${EXTRACT_SUFX} \
		nss-softokn-3.14.3-23.3.el6_8${EXTRACT_SUFX} \
		nss-softokn-freebl-3.14.3-23.3.el6_8${EXTRACT_SUFX}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Network Security Services (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	MPL

RPMVERSION=	8.el6
USES=		linux:c6
USE_LINUX=	nspr sqlite3
USE_LINUX_RPM=	yes
USE_LDCONFIG=	yes

SRC_DISTFILES=	${DISTNAME}${SRC_SUFX}:SOURCE \
		nss-util-${PORTVERSION}-2.el6.src.rpm:SOURCE \
		nss-softokn-3.14.3-23.3.el6_8.src.rpm:SOURCE

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
