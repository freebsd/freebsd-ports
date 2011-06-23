# New Ports collection makefile for:	megacli
# Date created:		12 April 2009
# Whom:			Vladimir Laskov <samflanker@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	megacli
PORTVERSION=	8.01.06
CATEGORIES=	sysutils
MASTER_SITES=	http://www.lsi.com/downloads/Public/MegaRAID%20Common%20Files/
DISTNAME=	${PORTVERSION}_FreeBSD_MegaCLI

MAINTAINER=	samflanker@gmail.com
COMMENT=	SAS MegaRAID FreeBSD MegaCLI

RESTRICTED=	Source recipient must acknowledge license. Reproduction or redistribution prohibited. See http://www.lsi.com/lookup/License.aspx

FETCH_BEFORE_ARGS=	-o ${DISTDIR}/${DISTFILES}

ONLY_FOR_ARCHS=	i386 amd64
IA32_BINARY_PORT=	yes

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	sbin/MegaCli

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/MegaCli ${PREFIX}/sbin

.include <bsd.port.mk>
