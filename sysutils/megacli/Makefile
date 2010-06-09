# New Ports collection makefile for:	megacli
# Date created:		12 April 2009
# Whom:			Vladimir Ermakov <samflanker@gmail.com>
#
# $FreeBSD$

PORTNAME=	megacli
PORTVERSION=	8.00.16
CATEGORIES=	sysutils
MASTER_SITES=	http://www.lsi.com/DistributionSystem/AssetDocument/
DISTNAME=	${PORTVERSION}_FreeBSD_MegaCLI

MAINTAINER=	samflanker@gmail.com
COMMENT=	SAS MegaRAID FreeBSD MegaCLI

ONLY_FOR_ARCHS=	i386 amd64
IA32_BINARY_PORT=	yes

RESTRICTED=	May not be redistributed in binary form
NO_CDROM=	yes

USE_ZIP=	yes

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	sbin/MegaCli

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/MegaCli  ${PREFIX}/sbin

.include <bsd.port.mk>
