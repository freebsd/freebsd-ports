# New ports collection makefile for:	zxfer
# Date created:				07 April 2011
# Whom:					Ivan Dreckman <ivannashdreckman@fastmail.fm>
#
# $FreeBSD$
#

PORTNAME=	zxfer
PORTVERSION=	0.9.8
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ivannashdreckman@fastmail.fm
COMMENT=	Easily and reliably transfer ZFS filesystems

RUN_DEPENDS=	rsync:${PORTSDIR}/net/rsync

USE_BZIP2=	yes
NO_BUILD=	yes

LICENSE=	BSD

PLIST_FILES=	sbin/zxfer

MAN8=		zxfer.8
MANCOMPRESSED=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/zxfer ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/zxfer.8.gz ${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
