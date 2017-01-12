# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	gnutls
PORTVERSION=	2.8.5
PORTREVISION=	5
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	GNU Transport Layer Security library

USES=		linux:c6
USE_LINUX_RPM=	yes
USE_LINUX=	libtasn1 libgcrypt libgpg-error

RPMVERSION=	19.el6_7
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION="${PORTVERSION}"
DESCR=		${.CURDIR}/../gnutls/pkg-descr

.include <bsd.port.mk>
