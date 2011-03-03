# New ports collection makefile for:	security/linux-f10-nss
# Date created:				2009-05-04
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	nss
PORTVERSION=	3.12.3.99.3
PORTREVISION=	1
CATEGORIES=	security linux
MASTER_SITES=	CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Network Security Services (Linux Fedora 10)

CONFLICTS=	linux-f8-nss-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	nspr sqlite3
LINUX_DIST_VER=	10
RPMVERSION=	2.10.6.fc10
USE_LDCONFIG=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
