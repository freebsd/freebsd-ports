# Created by: Andy Kosela <akosela@andykosela.com>
# $FreeBSD$

PORTNAME=	bpkg
PORTVERSION=	2.1.7
CATEGORIES=	ports-mgmt
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	akosela@andykosela.com
COMMENT=	Simple tool for displaying information about ports

DEPRECATED=	Does not support pkgng
EXPIRATION_DATE=	2015-01-06

NO_BUILD=	yes
SUB_FILES=	bpkg.sh

PLIST_FILES=	bin/bpkg man/man8/bpkg.8.gz

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/bpkg.sh ${STAGEDIR}${PREFIX}/bin/bpkg
	${INSTALL_MAN} ${FILESDIR}/bpkg.8 ${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
