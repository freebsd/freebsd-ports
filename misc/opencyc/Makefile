# New ports collection makefile for:	opencyc
# Date created:				Apr 19 2003
# Whom:					Alex Semenyaka <alex@rinet.ru>
#
# $FreeBSD$
#

PORTNAME=	opencyc
PORTVERSION=	0.7.0
PORTREVISION=	3
CATEGORIES=	misc linux
MASTER_SITES=	SF/${PORTNAME}/OldFiles
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General knowledge base and commonsense reasoning engine

USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs
NO_BUILD=	yes

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

post-extract:
	cd ${WRKSRC}/doc && ${RM} '#migration.txt#' 'package-list.~1~' '.#faq' '.#migration.txt'

pre-patch:
	@${BRANDELF} -t Linux ${WRKSRC}/run/bin/latest.bin

do-install:
	@${CP} -PRpf ${WRKSRC} ${PREFIX}

.include <bsd.port.mk>
