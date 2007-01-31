# New ports collection makefile for:	FreeSBIE
# Date created:		27 March 2003
# Whom:			Thomas E. Zander <riggs@rrr.de>
#
# $FreeBSD$
#

PORTNAME=	freesbie
PORTVERSION=	2.0.20060202
CATEGORIES=	sysutils
MASTER_SITES=	http://www.rrr.de/~riggs/freesbie/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/2.0.//}

MAINTAINER=	riggs@rrr.de
COMMENT=	Yet another cool answer to the system-on-cd question

USE_BZIP2=	yes
USE_CDRTOOLS=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}2

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 504000
IGNORE=		earlier FreeBSD versions then 5.4-RELEASE are not supported
.endif

do-install:
	@${MKDIR} ${DATADIR}
	@ cd ${WRKSRC} && ${FIND} . -type f -print | \
		${CPIO} --quiet -pdum -R ${BINOWN}:${BINGRP} ${DATADIR}
	@ cd ${DATADIR} && ${FIND} . -type d -print | ${XARGS} ${CHMOD} 0755
	@ cd ${PREFIX} && ${FIND} share/${PORTNAME} -type f -print | \
		${SORT} -r > ${TMPPLIST}
	@ cd ${PREFIX} && ${FIND} share/${PORTNAME} -type d -print | \
		${SORT} -r | ${SED} -e 's#^#@dirrm #' >> ${TMPPLIST}

.include <bsd.port.post.mk>
