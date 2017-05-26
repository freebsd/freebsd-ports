# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	nss
PORTVERSION=	3.28.4
CATEGORIES=	security linux
LIB_DISTNAMES=	${DISTNAME} \
		${PORTNAME}-util-${PORTVERSION}-1.0.el7_3 \
		${PORTNAME}-softokn-3.16.2.3-14.4.el7 \
		${PORTNAME}-softokn-freebl-3.16.2.3-14.4.el7
SRC_DISTFILES=	${DISTNAME}${SRC_SUFX}:SOURCE \
		${PORTNAME}-util-${PORTVERSION}-1.0.el7_3${SRC_SUFX}:SOURCE \
		${PORTNAME}-softokn-3.16.2.3-14.4.el7${SRC_SUFX}:SOURCE

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Network Security Services (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-c6-${PORTNAME}-[0-9]*

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
RPMVERSION=	1.0.el7_3
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	nspr sqlite3
USE_LINUX_RPM=	yes

.include <bsd.port.mk>
