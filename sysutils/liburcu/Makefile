PORTNAME=	liburcu
PORTVERSION=	0.13.0
CATEGORIES=	sysutils
MASTER_SITES=	http://lttng.org/files/urcu/
DISTNAME=	userspace-rcu-${PORTVERSION}

MAINTAINER=	freebsd@dns-lab.com
COMMENT=	Userspace read-copy-update (RCU) data synchronization library

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/lgpl-2.1.txt

USES=		libtool pathfix tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--docdir=${DOCSDIR}
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

PLIST_SUB=	SO_SHORT_VER=8 \
		SO_VER=8.0.0

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
