# Created by: David Shane Holden <dpejesh@yahoo.com>
# $FreeBSD$

PORTVERSION=		2.0.3
PORTREVISION=		1
PKGNAMESUFFIX=		2

.include "${.CURDIR}/../pacemaker1/Makefile.common"

CONFIGURE_ARGS+=	--with-noarch-pkgconfigdir=${PREFIX}/libdata/pkgconfig

CONFLICTS+=		pacemaker1-[0-9]*

post-patch: post-patch-common

.include <bsd.port.mk>
