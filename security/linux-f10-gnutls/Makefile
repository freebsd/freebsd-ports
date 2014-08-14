# Created by: Stas Timokhin <devel@stasyan.com>
# $FreeBSD: head/security/linux-f10-gnutls/Makefile 362314 2014-07-20 12:06:46Z rene $

PORTNAME=	gnutls
PORTVERSION=	2.4.2
PORTREVISION=	1
CATEGORIES=	security linux
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	GNU Transport Layer Security library

#FORBIDDEN=	http://www.freshports.org/vuxml.php?vid=f645aa90-a3e8-11e3-a422-3c970e169bc2

USE_LINUX_RPM=	yes
USE_LINUX_APPS=	libtasn1 libgcrypt libgpg-error
LINUX_DIST_VER=	10
RPMVERSION=	5.fc10
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION="${PORTVERSION}"
DESCR=		${PORTSDIR}/security/gnutls/pkg-descr

.include <bsd.port.mk>
