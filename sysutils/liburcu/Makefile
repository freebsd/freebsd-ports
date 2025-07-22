PORTNAME=	liburcu
DISTVERSION=	0.15.3
CATEGORIES=	sysutils
MASTER_SITES=	https://lttng.org/files/urcu/
DISTNAME=	userspace-rcu-${DISTVERSION}

MAINTAINER=	freebsd@dns-lab.com
COMMENT=	Userspace read-copy-update (RCU) data synchronization library
WWW=		https://liburcu.org/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSES/LGPL-2.1-or-later.txt

USES=		libtool pathfix tar:bzip2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

TEST_TARGET=	check
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--docdir=${DOCSDIR}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
