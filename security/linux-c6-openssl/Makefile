# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	openssl
PORTVERSION=	1.0.1e
PORTREVISION=	12
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	OpenSSL toolkit (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-f10-openssl-[0-9]*

USES=		linux:c6
USE_LINUX_RPM=	yes
RPMVERSION=	48.el6_8.3
USE_LDCONFIG=	yes

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
