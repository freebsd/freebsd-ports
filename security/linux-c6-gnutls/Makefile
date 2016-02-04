# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	gnutls
PORTVERSION=	2.8.5
PORTREVISION=	2
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	GNU Transport Layer Security library

USE_LINUX=	c6
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	libtasn1 libgcrypt libgpg-error

RPMVERSION=	18.el6
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION="${PORTVERSION}"
DESCR=		${.CURDIR}/../gnutls/pkg-descr

.include <bsd.port.mk>
