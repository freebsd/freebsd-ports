# Created by: Mikolaj Golub <trociny@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cmogstored
PORTVERSION=	1.5.0
CATEGORIES=	sysutils
MASTER_SITES=	http://bogomips.org/cmogstored/files/

MAINTAINER=	trociny@FreeBSD.org
COMMENT=	Alternative mogstored implementation for MogileFS

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_powerpc64=	Does not build

PLIST_FILES=	sbin/cmogstored \
		man/man1/cmogstored.1.gz

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--bindir=${PREFIX}/sbin \
		--mandir=${PREFIX}/man
USE_RC_SUBR=	cmogstored

regression-test: build
	${MAKE} -C ${WRKSRC} check

.include <bsd.port.mk>
