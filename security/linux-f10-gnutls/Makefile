# Created by: Stas Timokhin <devel@stasyan.com>
# $FreeBSD: head/security/linux-f10-gnutls/Makefile 362314 2014-07-20 12:06:46Z rene $

PORTNAME=	gnutls
PORTVERSION=	2.4.2
PORTREVISION=	2
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	GNU Transport Layer Security library

USE_LINUX=	f10
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	libtasn1 libgcrypt libgpg-error

RPMVERSION=	5.fc10
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION="${PORTVERSION}"
DESCR=		${PORTSDIR}/security/gnutls/pkg-descr

.include <bsd.port.mk>
