PORTNAME=	cmogstored
PORTVERSION=	1.8.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://yhbt.net/cmogstored/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Alternative mogstored implementation for MogileFS
WWW=		https://yhbt.net/cmogstored/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_mips=		failst to compile: fdmap.c:89: undefined reference to `__sync_add_and_fetch_4'
BROKEN_mips64=		failst to compile: fdmap.c:89: undefined reference to `__sync_add_and_fetch_4'

USES=		compiler:c11

PLIST_FILES=	sbin/cmogstored \
		share/man/man1/cmogstored.1.gz

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--bindir=${PREFIX}/sbin
USE_RC_SUBR=	cmogstored
TEST_TARGET=	check

.include <bsd.port.mk>
