# Created by: Leo Vandewoestijne <freebsd@dns-lab.com>
# $FreeBSD$

PORTNAME=	liburcu
PORTVERSION=	0.10.0
CATEGORIES=	sysutils
MASTER_SITES=	http://lttng.org/files/urcu/
DISTNAME=	userspace-rcu-${PORTVERSION}

MAINTAINER=	mmokhi@FreeBSD.org
COMMENT=	Userspace read-copy-update (RCU) data synchronization library

LICENSE=	LGPL21

BROKEN_aarch64=	Fails to build: Cannot build: unrecognized architecture detected
BROKEN_mips=	Fails to build: undefined reference to `__sync_bool_compare_and_swap_4
BROKEN_mips64=	Fails to build: undefined reference to `__sync_bool_compare_and_swap_4

PLIST_SUB=	SO_SHORT_VER=6 \
		SO_VER=6.0.0

USES=		pathfix libtool tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--docdir=${DOCSDIR}
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.include <bsd.port.mk>
