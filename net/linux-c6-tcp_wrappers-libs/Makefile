# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	tcp_wrappers-libs
PORTVERSION=	7.6
PORTREVISION=	2
CATEGORIES=	net linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Libraries tcp wrappers (Linux CentOS ${LINUX_DIST_VER})

USE_LINUX=	c6
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	xorglibs

RPMVERSION=	58.el6
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/usr/share/doc/tcp_wrappers-${PORTVERSION}

SRC_DISTFILES=	tcp_wrappers-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}:SOURCE

.include <bsd.port.mk>
