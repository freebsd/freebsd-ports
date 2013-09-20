# Created by: bsam
# $FreeBSD$

PORTNAME=	openssl
PORTVERSION=	0.9.8g
CATEGORIES=	security linux
MASTER_SITES=	CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	The OpenSSL toolkit (Linux Fedora 10)

CONFLICTS=	linux-openssl-[0-9]* linux-f8-openssl-[0-9]*

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	10
RPMVERSION=	14.fc10
BRANDELF_FILES=	usr/bin/openssl
USE_LDCONFIG=	yes

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

NO_STAGE=	yes
.include <bsd.port.mk>
