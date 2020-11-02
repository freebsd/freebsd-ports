# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	zfs-snapshot-clean
PORTVERSION=	0.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to sieve ZFS snapshots as per given spec a la 'pdumpfs-clean'

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	knu

NO_BUILD=	yes
PLIST_FILES=	sbin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin/

.include <bsd.port.mk>
