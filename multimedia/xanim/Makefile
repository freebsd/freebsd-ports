# New ports collection makefile for:	xanim
# Version required:     2.70.6.3
# Date created:         Sat Nov 5 11:43:03 PST 1994
# Whom:                 piero
#
# $Id: Makefile,v 1.10 1996/11/18 11:29:30 asami Exp $
#

DISTNAME=       xanim27063
PKGNAME=        xanim-2.70.6.3
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://xanim.va.pubnix.com/\
		ftp://xanim.va.pubnix.com/modules/
DISTFILES=	${EXTRACT_ONLY} ${EXTRA_FILES}

EXTRACT_ONLY=   ${DISTNAME}.tar.gz
EXTRA_FILES=    xa2.0_cvid_netbsd386.o.Z xa2.0_iv32_netbsd386.o.Z \
		xa1.0_cyuv_netbsd386.o.Z
USE_IMAKE=	yes

post-extract:
	@for file in ${EXTRA_FILES}; do \
	  cp ${DISTDIR}/$$file ${WRKSRC}; \
	  uncompress ${WRKSRC}/$$file; \
	done

.include <bsd.port.mk>
