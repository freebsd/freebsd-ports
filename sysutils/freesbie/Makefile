# New ports collection makefile for:	FreeSBIE
# Date created:		27 March 2003
# Whom:			Thomas E. Zander <riggs@rrr.de>
#
# $FreeBSD$
#

PORTNAME=	freesbie
PORTVERSION=	0.0.20040207
CATEGORIES=	sysutils
MASTER_SITES=	http://www.stud.uni-karlsruhe.de/~uedc/freesbie/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/0.0.//}

MAINTAINER=	riggs@rrr.de
COMMENT=	Yet another cool answer to the system-on-cd question

RUN_DEPENDS=	mkisofs:${PORTSDIR}/sysutils/mkisofs \
		create_compressed_fs:${PORTSDIR}/sysutils/cloop-utils

USE_BZIP2=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	@${MKDIR} ${DATADIR}
	@ cd ${WRKSRC} && ${FIND} * -type f -print | \
		${CPIO} --quiet -pdum -R ${BINOWN}:${BINGRP} ${DATADIR}
	@ cd ${DATADIR} && ${FIND} * -type d -print | ${XARGS} ${CHMOD} 0755
	@ cd ${PREFIX} && ${FIND} share/${PORTNAME} -type f -print | \
		${SORT} -r > ${TMPPLIST}
	@ cd ${PREFIX} && ${FIND} share/${PORTNAME} -type d -print | \
		${SORT} -r | ${SED} -e 's#^#@dirrm #' >> ${TMPPLIST}

.include <bsd.port.mk>
