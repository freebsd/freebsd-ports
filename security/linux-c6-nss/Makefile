# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	nss
PORTVERSION=	3.21.0
PORTREVISION=	1
CATEGORIES=	security linux
DISTFILES=	#
LIB_DISTFILES=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}.${LINUX_RPM_ARCH}.rpm \
		nss-util-${PORTVERSION}-2.el6.${LINUX_RPM_ARCH}.rpm \
		nss-softokn-3.14.3-23.el6_7.${LINUX_RPM_ARCH}.rpm \
		nss-softokn-freebl-3.14.3-23.el6_7.${LINUX_RPM_ARCH}.rpm

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Network Security Services (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-f10-nss-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
RPMVERSION=	8.el6
USE_LINUX=	c6
USE_LINUX_APPS=	nspr sqlite3

USE_LINUX_RPM=	yes
USE_LDCONFIG=	yes

SRC_DISTFILES=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}:SOURCE \
		nss-util-${PORTVERSION}-2.el6.src.rpm:SOURCE \
		nss-softokn-3.14.3-23.el6_7.src.rpm:SOURCE

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
