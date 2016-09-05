# Created by: Stas Timokhin <devel@stasyan.com>
# $FreeBSD$

PORTNAME=	gnutls
PORTVERSION=	2.4.2
PORTREVISION=	2
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	GNU Transport Layer Security library

USES=		linux:f10
USE_LINUX_RPM=	yes
USE_LINUX=	libtasn1 libgcrypt libgpg-error

RPMVERSION=	5.fc10
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION="${PORTVERSION}"
DESCR=		${PORTSDIR}/security/gnutls/pkg-descr

.include <bsd.port.mk>
