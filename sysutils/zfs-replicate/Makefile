# Created by: Jui-Nan Lin <jnlin@freebsd.cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	zfs-replicate
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://blogs.sun.com/constantin/resource/
DISTNAME=	${PORTNAME}_v${PORTVERSION}

MAINTAINER=	jnlin@freebsd.cs.nctu.edu.tw
COMMENT=	ZFS Snapshot Replication Script

RUN_DEPENDS=	ksh:shells/pdksh

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USES=	tar:bzip2

PLIST_FILES=	sbin/zfs-replicate

do-patch:
	@${REINPLACE_CMD} -e 's|^#!/bin/ksh|#!${PREFIX}/bin/ksh|g' \
		${WRKSRC}/zfs-replicate_v${PORTVERSION}
	@${REINPLACE_CMD} -e 's|/usr/sbin/zfs|/sbin/zfs|g' \
		${WRKSRC}/zfs-replicate_v${PORTVERSION}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/zfs-replicate_v${PORTVERSION} \
		${STAGEDIR}${PREFIX}/sbin/zfs-replicate

.include <bsd.port.mk>
