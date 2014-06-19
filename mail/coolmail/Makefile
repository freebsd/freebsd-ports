# Created by: Udo Schweigert <ust@cert.siemens.de>
# $FreeBSD$

PORTNAME=	coolmail
PORTVERSION=	1.3
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=system/mail/biffs
EXTRACT_SUFX=	.tgz

MAINTAINER=	udo.schweigert@siemens.com
COMMENT=	A Xbiff like mail tool with animated 3D graphics

PLIST_FILES=	bin/coolmail \
		man/man1/coolmail.1.gz

USE_XORG=	x11 xext xmu xi
PATCH_STRIP=	-p1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/coolmail ${STAGEDIR}${PREFIX}/bin/coolmail
	${INSTALL_MAN} ${WRKSRC}/coolmail.man ${STAGEDIR}${PREFIX}/man/man1/coolmail.1

.include <bsd.port.mk>
