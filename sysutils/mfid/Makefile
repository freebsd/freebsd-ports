# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mfid
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/feld

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Monitoring daemon for mfi RAID controllers

USE_RC_SUBR=	mfid
PLIST_FILES+=	sbin/mfid

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mfid ${STAGEDIR}${PREFIX}/sbin/mfid

.include <bsd.port.mk>
