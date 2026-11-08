PORTNAME=	liburcu
DISTVERSION=	0.15.7
CATEGORIES=	sysutils
MASTER_SITES=	https://lttng.org/files/urcu/
DISTNAME=	userspace-rcu-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Userspace read-copy-update (RCU) data synchronization library
WWW=		https://liburcu.org/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSES/LGPL-2.1-or-later.txt

TEST_DEPENDS=	bash:shells/bash

USES=		autoreconf libtool pathfix tar:bzip2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--docdir=${DOCSDIR}
CONFIGURE_ENV=	ac_cv_prog_cc_g=no ac_cv_prog_cxx_g=no

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
