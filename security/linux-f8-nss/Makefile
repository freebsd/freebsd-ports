# New ports collection makefile for:	security/linux-f8-nss
# Date created:				2009-04-05
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	nss
PORTVERSION=	3.12.2.0
PORTREVISION=	1
CATEGORIES=	security linux
PKGNAMEPREFIX=	linux-f8-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Network Security Services (Linux Fedora 8)

CONFLICTS=	linux-nss-[0-9]* linux-f10-nss-[0-9]*

DEPRECATED=	End of Life since Jan 7, 2009
EXPIRATION_DATE=2011-04-01

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	nspr sqlite3
LINUX_DIST_VER=	8
RPMVERSION=	1.1.fc8
USE_LDCONFIG=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
