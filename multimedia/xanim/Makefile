# New ports collection makefile for:	xanim
# Version required:     2.70.3
# Date created:         Sat Nov 5 11:43:03 PST 1994
# Whom:                 piero
#
# $Id: Makefile,v 1.6 1996/03/08 14:37:19 erich Exp $
#

DISTNAME=       xanim2703
PKGNAME=        xanim-2.70.3
CATEGORIES+=	graphics x11
MASTER_SITES=	ftp://ftp.portal.com/pub/podlipec/ \
		ftp://ftp.portal.com/pub/podlipec/cinepak/ \
		ftp://ftp.portal.com/pub/podlipec/indeo/
EXTRACT_ONLY=	xanim2703.tar.gz
EXTRA_FILES=	xa2.0_cvid_netbsd386.o.Z xa2.0_iv32_netbsd386.o.Z
DISTFILES=	${EXTRACT_ONLY} ${EXTRA_FILES}

USE_IMAKE=	yes

post-extract:
	@for file in ${EXTRA_FILES}; do \
	  cp ${DISTDIR}/$$file ${WRKSRC}; \
	  uncompress ${WRKSRC}/$$file; \
	done

.include <bsd.port.mk>

