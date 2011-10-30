# New Ports collection makefile for:	megacli
# Date created:		12 April 2009
# Whom:			Vladimir Laskov <samflanker@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	megacli
PORTVERSION=	8.02.16
CATEGORIES=	sysutils
MASTER_SITES=	http://www.lsi.com/downloads/Public/MegaRAID%20Common%20Files/ \
		CRITICAL
DISTNAME=	${PORTVERSION}_MegaCLI

MAINTAINER=	samflanker@gmail.com
COMMENT=	SAS MegaRAID FreeBSD MegaCLI

RESTRICTED=	Source recipient must acknowledge license. Reproduction or redistribution prohibited. See http://www.lsi.com/lookup/License.aspx

FETCH_BEFORE_ARGS=	-o ${DISTDIR}/${DISTFILES}

ONLY_FOR_ARCHS=	i386 amd64

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	sbin/MegaCli

.include <bsd.port.pre.mk>
do-install:
.if ${ARCH} == "i386"
		${INSTALL_PROGRAM} ${WRKSRC}/FREEBSD/MegaCli ${PREFIX}/sbin/MegaCli
.elif ${ARCH} == "amd64"
		${INSTALL_PROGRAM} ${WRKSRC}/FREEBSD/MegaCli64 ${PREFIX}/sbin/MegaCli
.endif
.include <bsd.port.post.mk>
