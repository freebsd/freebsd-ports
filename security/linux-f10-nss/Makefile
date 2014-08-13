# Created by: bsam
# $FreeBSD: head/security/linux-f10-nss/Makefile 362314 2014-07-20 12:06:46Z rene $

PORTNAME=	nss
PORTVERSION=	3.12.3.99.3
PORTREVISION=	1
CATEGORIES=	security linux
MASTER_SITES=	CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Network Security Services (Linux Fedora 10)

#FORBIDDEN=	http://www.freshports.org/vuxml.php?vid=9ccfee39-3c3b-11df-9edc-000f20797ede

CONFLICTS=	linux-f8-nss-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	nspr sqlite3
LINUX_DIST_VER=	10
RPMVERSION=	2.10.6.fc10
USE_LDCONFIG=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
