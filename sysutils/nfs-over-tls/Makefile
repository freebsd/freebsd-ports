PORTNAME=	nfs-over-tls
DISTVERSION=	1.2
CATEGORIES=	sysutils
MASTER_SITES=	https://people.freebsd.org/~rmacklem/nfs-over-tls/

MAINTAINER=	rmacklem@freebsd.org
COMMENT=	Utilities for NFS over TLS

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libssl.so:security/openssl

USES=		kmod ssl

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1300133
IGNORE=		requires FreeBSD 13 or later with in-kernel TLS support \
		and OpenSSL with KTLS enabled
.endif

.if exists(/usr/sbin/rpc.tlsclntd)
IGNORE=		already included in the base system
.endif

.include <bsd.port.post.mk>
