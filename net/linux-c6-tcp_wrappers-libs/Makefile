# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	tcp_wrappers-libs
PORTVERSION=	7.6
PORTREVISION=	3
CATEGORIES=	net linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Libraries tcp wrappers (Linux CentOS ${LINUX_DIST_VER})

RPMVERSION=	58.el6
USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	xorglibs
USE_LINUX_RPM=	yes

DOCSDIR=	${PREFIX}/usr/share/doc/tcp_wrappers-${PORTVERSION}

SRC_DISTFILES=	tcp_wrappers-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}:SOURCE

.include <bsd.port.mk>
