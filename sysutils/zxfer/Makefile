# Created by: Ivan Dreckman <ivannashdreckman@fastmail.fm>
# $FreeBSD$

PORTNAME=	zxfer
PORTVERSION=	0.9.8
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easily and reliably transfer ZFS filesystems

LICENSE=	BSD

RUN_DEPENDS=	rsync:${PORTSDIR}/net/rsync

USE_BZIP2=	yes
NO_BUILD=	yes

PLIST_FILES=	sbin/zxfer

MAN8=		zxfer.8
MANCOMPRESSED=	yes

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/zxfer ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/zxfer.8.gz ${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
