# New ports collection makefile for:	security/linux-f10-nss
# Date created:				2009-05-04
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	nss
PORTVERSION=	3.12.2.0
CATEGORIES=	security linux
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Network Security Services (Linux Fedora 10)

CONFLICTS=	linux-f8-nss-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	nspr sqlite3
LINUX_DIST_VER=	10
RPMVERSION=	5.fc10
USE_LDCONFIG=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
