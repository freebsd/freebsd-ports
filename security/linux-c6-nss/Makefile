# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	nss
PORTVERSION=	3.21.0
PORTREVISION=	1
CATEGORIES=	security linux
LIB_DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		nss-util-${PORTVERSION}-2.el6${EXTRACT_SUFX} \
		nss-softokn-3.14.3-23.el6_7${EXTRACT_SUFX} \
		nss-softokn-freebl-3.14.3-23.el6_7${EXTRACT_SUFX}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Network Security Services (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-f10-nss-[0-9]*

RPMVERSION=	8.el6
USES=		linux:c6
USE_LINUX=	nspr sqlite3
USE_LINUX_RPM=	yes
USE_LDCONFIG=	yes

SRC_DISTFILES=	${DISTNAME}${SRC_SUFX}:SOURCE \
		nss-util-${PORTVERSION}-2.el6.src.rpm:SOURCE \
		nss-softokn-3.14.3-23.el6_7.src.rpm:SOURCE

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
