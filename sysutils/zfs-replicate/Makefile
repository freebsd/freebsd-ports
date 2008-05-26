# New ports collection makefile for:	zfs-replicate
# Date created:		2008-05-26
# Whom:			Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	zfs-replicate
PORTVERSION=	0.4
CATEGORIES=	sysutils
MASTER_SITES=	http://blogs.sun.com/constantin/resource/
DISTNAME=	${PORTNAME}_v${PORTVERSION}

MAINTAINER=	jnlin@csie.nctu.edu.tw
COMMENT=	A ZFS Snapshot Replication Script

RUN_DEPENDS=	ksh93:${PORTSDIR}/shells/ksh93

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_BZIP2=	yes

PLIST_FILES=	sbin/zfs-replicate

do-patch:
	@${REINPLACE_CMD} -e 's|^#!/bin/ksh|#!${PREFIX}/bin/ksh93|g' ${WRKSRC}/zfs-replicate

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/zfs-replicate ${PREFIX}/sbin/

.include <bsd.port.mk>
