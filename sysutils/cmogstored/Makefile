# Created by: Mikolaj Golub <trociny@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cmogstored
PORTVERSION=	1.6.0
CATEGORIES=	sysutils
MASTER_SITES=	http://bogomips.org/cmogstored/files/

MAINTAINER=	trociny@FreeBSD.org
COMMENT=	Alternative mogstored implementation for MogileFS

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_powerpc64=	Does not build: internal compiler error: Segmentation fault

PLIST_FILES=	sbin/cmogstored \
		man/man1/cmogstored.1.gz

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--bindir=${PREFIX}/sbin
USE_RC_SUBR=	cmogstored
TEST_TARGET=	check

.include <bsd.port.mk>
