# Created by: lme
# $FreeBSD$

PORTNAME=	avahi-libs
PORTVERSION=	0.6.25
PORTREVISION=	4
CATEGORIES=	net linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Libraries for Avahi (Linux CentOS ${LINUX_DIST_VER})

USES=		linux:c6
USE_LINUX_RPM=	yes

RPMVERSION=	15.el6_8.1
USE_LDCONFIG=	yes
SRC_DISTFILES=	${PORTNAME:S/-libs//}-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}:SOURCE
DESCR=		${.CURDIR}/../avahi/pkg-descr

.include <bsd.port.mk>
