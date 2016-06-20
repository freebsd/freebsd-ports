# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	cups-libs
PORTVERSION=	1.4.2
PORTREVISION=	5
CATEGORIES=	print linux
MASTER_SITES=	CENTOS_LINUX

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Common UNIX Printing System libraries

USE_LINUX=	c6
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	gnutls
SRC_DISTFILES=	cups-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}:SOURCE
RPMVERSION=	74.el6
USE_LDCONFIG=	yes

DESCR=		${.CURDIR}/../cups/pkg-descr

.include <bsd.port.mk>
