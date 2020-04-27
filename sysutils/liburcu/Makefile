# Created by: Leo Vandewoestijne <freebsd@dns-lab.com>
# $FreeBSD$

PORTNAME=	liburcu
PORTVERSION=	0.12.1
CATEGORIES=	sysutils
MASTER_SITES=	http://lttng.org/files/urcu/
DISTNAME=	userspace-rcu-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Userspace read-copy-update (RCU) data synchronization library

LICENSE=	LGPL21

PLIST_SUB=	SO_SHORT_VER=6 \
		SO_VER=6.1.0

USES=		pathfix libtool tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--docdir=${DOCSDIR}
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
