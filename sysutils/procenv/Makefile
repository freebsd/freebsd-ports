# Created by: James Hunt <james.hunt@ubuntu.com>
# $FreeBSD$

PORTNAME=	procenv
PORTVERSION=	0.21
CATEGORIES=	sysutils
MASTER_SITES=	https://launchpad.net/procenv/trunk/${PORTVERSION}/+download/ \
		DEBIAN \
		http://people.canonical.com/~jhunt/debian/procenv/

MAINTAINER=	james.hunt@ubuntu.com
COMMENT=	Utility to show process environment

LICENSE=	GPLv3

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
FETCH_ARGS=	-Fpr

MAN1=		procenv.1
PLIST_FILES=	bin/procenv

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800505
BROKEN=		does not build on old ${OPSYS} versions
.endif

.include <bsd.port.post.mk>
