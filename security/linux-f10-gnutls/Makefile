# New ports collection makefile for:	security/linux-f10-gnutls
# Date created:				10 Nov 2010
# Whom:					Stas Timokhin <devel@stasyan.com>
# $FreeBSD$
#

PORTNAME=	gnutls
PORTVERSION=	2.4.2
PORTREVISION=	1
CATEGORIES=	security linux
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	GNU Transport Layer Security library

USE_LINUX_RPM=	yes
USE_LINUX_APPS=	libtasn1 libgcrypt libgpg-error
LINUX_DIST_VER=	10
RPMVERSION=	5.fc10
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION="${PORTVERSION}"
DESCR=		${.CURDIR}/../gnutls/pkg-descr

.include <bsd.port.mk>
