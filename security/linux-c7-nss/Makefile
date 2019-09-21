# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	nss
PORTVERSION=	3.44.0
DISTVERSIONSUFFIX=	-4.el7
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Network Security Services (Linux CentOS ${LINUX_DIST_VER})

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	nspr sqlite3
USE_LINUX_RPM=	yes

LIB_DISTNAMES=	${DISTNAME} \
		${PORTNAME}-pem-1.0.3-7.el7 \
		${PORTNAME}-util-${PORTVERSION}-3.el7 \
		${PORTNAME}-softokn-${PORTVERSION}-5.el7
SRC_DISTFILES=	${DISTNAME}${SRC_SUFX}:SOURCE \
		${PORTNAME}-pem-1.0.3-7.el7${SRC_SUFX}:SOURCE \
		${PORTNAME}-util-${PORTVERSION}-3.el7${SRC_SUFX}:SOURCE \
		${PORTNAME}-softokn-${PORTVERSION}-5.el7${SRC_SUFX}:SOURCE

CONFLICTS=	linux-c6-${PORTNAME}-[0-9]*
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
