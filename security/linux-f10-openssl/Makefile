# Created by: bsam
# $FreeBSD: head/security/linux-f10-openssl/Makefile 362314 2014-07-20 12:06:46Z rene $

PORTNAME=	openssl
PORTVERSION=	0.9.8g
CATEGORIES=	security linux
MASTER_SITES=	CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	OpenSSL toolkit (Linux Fedora 10)

#FORBIDDEN=	http://www.freshports.org/vuxml.php?vid=2ecb7b20-d97e-11e0-b2e2-00215c6a37bb|82b55df8-4d5a-11de-8811-0030843d3802

CONFLICTS=	linux-openssl-[0-9]* linux-f8-openssl-[0-9]*

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	10
RPMVERSION=	14.fc10
BRANDELF_FILES=	usr/bin/openssl
USE_LDCONFIG=	yes

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
