# Ports collection makefile for:	logcheck
# Version required:	1.1.1
# Date created:		9 December 1999
# Whom:			Dan Langille <dan@freebsddiary.org>
#
# $FreeBSD$
#

DISTNAME=	logcheck-1.1.1
CATEGORIES=	security
MASTER_SITES=	http://www.psionic.com/tools/

MAINTAINER=	ports@freebsddiary.org

PKGMESSAGE=	${WRKDIR}/MESSAGE

post-build:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${PKGDIR}/MESSAGE > ${PKGMESSAGE}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
