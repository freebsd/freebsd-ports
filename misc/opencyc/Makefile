# New ports collection makefile for:	opencyc
# Date created:				Apr 19 2003
# Whom:					Alex Semenyaka <alex@rinet.ru>
#
# $FreeBSD$
#

PORTNAME=	opencyc
PORTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	misc linux
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	alexs@snark.rinet.ru
COMMENT=	General knowledge base and commonsense reasoning engine

RUN_DEPENDS=	${LINUXBASE}/usr/X11R6/lib/libXrender.so.1:${PORTSDIR}/x11/linux-XFree86-libs

NO_BUILD=	yes
USE_LINUX=	yes

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

post-extract:
	cd ${WRKSRC}/doc && ${RM} '#migration.txt#' 'package-list.~1~' '.#faq' '.#migration.txt'

pre-patch:
	@${BRANDELF} -t Linux ${WRKSRC}/run/bin/latest.bin

do-install:
	@${CP} -PRpf ${WRKSRC} ${PREFIX}

.include <bsd.port.mk>
