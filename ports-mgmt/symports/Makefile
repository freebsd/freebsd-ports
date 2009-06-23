# New ports collection makefile for:   symports
# Date created:        Fri Jun 05 2009
# Whom:                Eitan Adler <EitanAdlerList@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	symports
PORTVERSION=	1.0
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://isis.poly.edu/~eitan/files/
DISTNAME=	auto-symlink-virtual-${PORTVERSION}

MAINTAINER=	EitanAdlerList@gmail.com
COMMENT=	Automatically generate symlinks for virtual categories

USE_BZIP2=	yes
NO_BUILD=	yes

MAN1=		symports.1
MANCOMPRESSED=	no

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/auto-symlink-virtual.sh ${PREFIX}/bin/${PORTNAME}

post-install:
	${INSTALL_MAN} ${WRKDIR}/${MAN1} ${MAN1PREFIX}/man/man1/${MAN1}

.include <bsd.port.mk>
