# New ports collection makefile for:	iv
# Version required:	3.1
# Date created:		23.sept.1994
# Whom:			adam
#
# $Id: Makefile,v 1.1.1.1 1994/09/24 15:33:57 adam Exp $
#

EXTRACT_SUFFIX=	.tar.Z
VERSION=	3.1
DISTNAME=	iv-${VERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFFIX}
WRKSRC=		${WRKDIR}/iv
MAKEFILE=	makefile

.if ${DISTNAME} != ${VERSION}
pre-fetch:
	if [ -f ${DISTDIR}/${DISTNAME} ] ; then \
	    mkdir -p ${DISTDIR}/${DISTNAME} ; \
	    ${MAKE} MASTER_SITES=ftp://interviews.stanford.edu/pub/ \
		DISTDIR=${DISTDIR}/${DISTNAME} DISTNAME=${VERSION} fetch ; \
	    mv ${DISTDIR}/${DISTNAME}/${VERSION}${EXTRACT_SUFFIX} \
		${DISTDIR}/${DISTFILES} ; \
	    rmdir ${DISTDIR}/${DISTNAME} ; \
	fi
.endif

.include <bsd.port.mk>
