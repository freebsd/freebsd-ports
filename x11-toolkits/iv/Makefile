# New ports collection makefile for:	iv
# Version required:	3.1
# Date created:		23.sept.1994
# Whom:			adam
#
# $Id: Makefile,v 1.2 1994/11/01 03:30:02 pst Exp $
#

EXTRACT_SUFFIX=	.tar.Z
VERSION=	3.1
DISTNAME=	iv-${VERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFFIX}
WRKSRC=		${WRKDIR}/iv
MAKEFILE=	makefile
NCFTPFLAGS=	-NP

.if ${DISTNAME} != ${VERSION}
pre-fetch:
	@if [ ! -f ${DISTDIR}/${DISTFILES} ]; then \
	    mkdir -p ${DISTDIR}/${DISTNAME} ; \
	    ${MAKE} MASTER_SITES=ftp://interviews.stanford.edu/pub/ \
		DISTDIR=${DISTDIR}/${DISTNAME} DISTNAME=${VERSION} fetch ; \
	    mv ${DISTDIR}/${DISTNAME}/${VERSION}${EXTRACT_SUFFIX} \
		${DISTDIR}/${DISTFILES} ; \
	    rmdir ${DISTDIR}/${DISTNAME} ; \
	fi
.endif

.include <bsd.port.mk>
