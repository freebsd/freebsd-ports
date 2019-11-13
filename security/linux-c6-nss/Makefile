# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	nss
PORTVERSION=	3.44.0
DISTVERSIONSUFFIX=	-7.el6_10
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Network Security Services (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	MPL20

USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	nspr sqlite3
USE_LINUX_RPM=	yes

LIB_DISTNAMES=	${DISTNAME} \
		${PORTNAME}-util-${PORTVERSION}-1.el6_10 \
		${PORTNAME}-softokn-${PORTVERSION}-5.el6_10
SRC_DISTFILES=	${DISTNAME}${SRC_SUFX}:SOURCE \
		${PORTNAME}-util-${PORTVERSION}-1.el6_10${SRC_SUFX}:SOURCE \
		${PORTNAME}-softokn-${PORTVERSION}-5.el6_10${SRC_SUFX}:SOURCE

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
