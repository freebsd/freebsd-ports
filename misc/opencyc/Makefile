# New ports collection makefile for:	opencyc
# Date created:				Apr 19 2003
# Whom:					Alex Semenyaka <alex@rinet.ru>
#
# $FreeBSD$
#

PORTNAME=	opencyc
PORTVERSION=	0.7.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	alexs@snark.rinet.ru
COMMENT=	General knowledge base and commonsense reasoning engine

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
