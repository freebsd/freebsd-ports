# Created by: lme
# $FreeBSD$

PORTNAME=	avahi-libs
PORTVERSION=	0.6.25
PORTREVISION=	1
CATEGORIES=	net linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Libraries for Avahi (Linux CentOS ${LINUX_DIST_VER})

USE_LINUX=	c6
USE_LINUX_RPM=	yes

RPMVERSION=	15.el6
USE_LDCONFIG=	yes
SRC_DISTFILES=	${PORTNAME:S/-libs//}-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}
DESCR=		${.CURDIR}/../avahi/pkg-descr

PLIST_FILES=	usr/lib/libavahi-client.so.3 usr/lib/libavahi-client.so.3.2.5 \
		usr/lib/libavahi-common.so.3 usr/lib/libavahi-common.so.3.5.1

.include <bsd.port.mk>
