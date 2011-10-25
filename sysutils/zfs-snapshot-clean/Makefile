# New ports collection makefile for:	zfs-snapshot-clean
# Date created:		2 January 2010
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	zfs-snapshot-clean
PORTVERSION=	0.1.3
CATEGORIES=	sysutils
MASTER_SITES=	http://cloud.github.com/downloads/knu/${PORTNAME}/ \
		ftp://ftp.iDaemons.org/pub/distfiles/

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A tool to sieve ZFS snapshots as per given spec a la 'pdumpfs-clean'

NO_BUILD=	yes
PLIST_FILES=	sbin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin/

.include <bsd.port.mk>
