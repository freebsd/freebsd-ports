# New ports collection makefile for:	iv
# Version required:	3.1
# Date created:		23.sept.1994
# Whom:			adam
#
# $Id: Makefile,v 1.6 1995/04/16 15:33:42 ache Exp $
#

VERSION=	3.1
# don't change this to "=" !
DISTNAME?=	iv-${VERSION}
MASTER_SITES=	ftp://interviews.stanford.edu/pub/
EXTRACT_SUFX=	.tar.Z
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

WRKSRC=		${WRKDIR}/iv
MAKEFILE=	makefile

.if ${DISTNAME} != ${VERSION}
pre-fetch:
	@if [ ! -f ${DISTDIR}/${DISTFILES} ]; then \
	    mkdir -p ${DISTDIR}/${DISTNAME} ; \
	    ${MAKE} \
		DISTDIR=${DISTDIR}/${DISTNAME} DISTNAME=${VERSION} fetch ; \
	    mv ${DISTDIR}/${DISTNAME}/${VERSION}${EXTRACT_SUFX} \
		${DISTDIR}/${DISTFILES} ; \
	    rmdir ${DISTDIR}/${DISTNAME} ; \
	fi
.endif

.include <bsd.port.mk>
