# Created by: Andy Kosela <akosela@andykosela.com>
# $FreeBSD$

PORTNAME=	bpkg
PORTVERSION=	2.1.7
CATEGORIES=	ports-mgmt
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	akosela@andykosela.com
COMMENT=	Simple tool for displaying information about ports

NO_BUILD=	yes
SUB_FILES=	bpkg.sh

PLIST_FILES=	bin/bpkg

MAN8=		bpkg.8

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/bpkg.sh ${PREFIX}/bin/bpkg
	${INSTALL_MAN} ${FILESDIR}/bpkg.8 ${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
