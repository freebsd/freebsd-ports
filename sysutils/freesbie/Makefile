# New ports collection makefile for:	FreeSBIE
# Date created:		27 March 2003
# Whom:			Thomas E. Zander <riggs@rrr.de>
#
# $FreeBSD$
#

PORTNAME=	freesbie
PORTVERSION=	0.0.20031113
CATEGORIES=	sysutils
MASTER_SITES=	http://www.stud.uni-karlsruhe.de/~uedc/freesbie/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/0.0.//}

MAINTAINER=	riggs@rrr.de
COMMENT=	Yet another cool answer to the system-on-cd question

RUN_DEPENDS=	mkisofs:${PORTSDIR}/sysutils/mkisofs

USE_BZIP2=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
CPIO?=		/usr/bin/cpio --quiet -pdum -R
SORT=		/usr/bin/sort -r
PLIST=		${WRKDIR}/PLIST

pre-install:
	@${TOUCH} ${PLIST}

do-install:
	@${MKDIR} ${DATADIR}
	@ cd ${WRKSRC} && ${FIND} * -type f -print | ${CPIO} ${BINOWN}:${BINGRP} ${DATADIR}
	@ cd ${DATADIR} && ${FIND} * -type d -print | ${XARGS} ${CHMOD} 0755
	@ cd ${PREFIX} && ${FIND} share/${PORTNAME} -type f -print | ${SORT} > ${TMPPLIST}
	@ cd ${PREFIX} && ${FIND} share/${PORTNAME} -type d -print | ${SORT} | ${SED} -e 's#^#@dirrm #' >> ${TMPPLIST}

.include <bsd.port.mk>
