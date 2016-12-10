# Created by: Leo Vandewoestijne <freebsd@dns-lab.com>
# $FreeBSD$

PORTNAME=	liburcu
PORTVERSION=	0.7.17
CATEGORIES=	sysutils
MASTER_SITES=	http://lttng.org/files/urcu/
DISTNAME=	userspace-rcu-${PORTVERSION}

MAINTAINER=	freebsd@dns-lab.com
COMMENT=	Userspace read-copy-update (RCU) data synchronization library

LICENSE=	LGPL21

PORTDOCS=	ChangeLog README cds-api.txt rcu-api.txt uatomic-api.txt

BROKEN_aarch64=	Fails to build: Cannot build: unrecognized architecture detected
BROKEN_armv6=	Fails to build: address argument to atomic builtin must be a pointer
BROKEN_mips=	Fails to build: undefined reference to `__sync_bool_compare_and_swap_4
BROKEN_mips64=	Fails to build: undefined reference to `__sync_bool_compare_and_swap_4

USES=		pathfix libtool tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--docdir=${DOCSDIR}
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.include <bsd.port.mk>
