# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	libgcrypt
PORTVERSION=	1.5.3
PORTREVISION=	3
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Crypto library based on code used in GnuPG (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-c6-${PORTNAME}-[0-9]*

LICENSE=	LGPL21+

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
RPMVERSION=	13.el7_3.1
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	libgpg-error
USE_LINUX_RPM=	yes

.include <bsd.port.mk>
