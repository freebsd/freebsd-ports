# $FreeBSD$

PORTNAME=	nfs-over-tls
DISTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	https://people.freebsd.org/~rmacklem/nfs-over-tls/

MAINTAINER=	rmacklem@freebsd.org
COMMENT=	Utilities for NFS over TLS

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=    libssl.so:security/openssl

USES=		kmod ssl

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1300042
BROKEN=         Requires FreeBSD 13 or later with in-kernel TLS support \
		and port's OpenSSL with KTLS enabled
.endif

.include <bsd.port.post.mk>
