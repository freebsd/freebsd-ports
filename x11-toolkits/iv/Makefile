# New ports collection makefile for:	iv
# Version required:	3.1
# Date created:		23.sept.1994
# Whom:			adam
#
# $Id: Makefile,v 1.4 1995/04/01 12:50:56 jkh Exp $
#

VERSION=	3.1
DISTNAME=	iv-${VERSION}
EXTRACT_SUFX=	.tar.Z
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

WRKSRC=		${WRKDIR}/iv
MAKEFILE=	makefile
NCFTPFLAGS=	-NP

.if ${DISTNAME} != ${VERSION}
pre-fetch:
	@if [ ! -f ${DISTDIR}/${DISTFILES} ]; then \
	    mkdir -p ${DISTDIR}/${DISTNAME} ; \
	    ${MAKE} MASTER_SITES=ftp://interviews.stanford.edu/pub/ \
		DISTDIR=${DISTDIR}/${DISTNAME} DISTNAME=${VERSION} fetch ; \
	    mv ${DISTDIR}/${DISTNAME}/${VERSION}${EXTRACT_SUFX} \
		${DISTDIR}/${DISTFILES} ; \
	    rmdir ${DISTDIR}/${DISTNAME} ; \
	fi
.endif

.include <bsd.port.mk>
