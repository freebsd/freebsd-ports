# New ports collection makefile for:	iv
# Version required:	3.1
# Date created:		23.sept.1994
# Whom:			adam
#
# $Id: Makefile,v 1.9 1995/06/04 01:12:38 asami Exp $
#

VERSION=	3.1
# don't change this to "=" !
DISTNAME?=	iv-${VERSION}
CATEGORIES=	x11
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

post-install:
	cd ${PREFIX}/interviews/man/mann; gzip -9nf *.n
# need these in ${PREFIX}/lib so that ldconfig can find them
	ln -fs ../interviews/lib/FREEBSD/libIV.so.3.1 ${PREFIX}/lib
	ln -fs ../interviews/lib/FREEBSD/libUnidraw.so.3.1 ${PREFIX}/lib
	ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
