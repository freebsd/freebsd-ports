# New ports collection makefile for:	xanim
# Version required:     2.70.6.4
# Date created:         Sat Nov 5 11:43:03 PST 1994
# Whom:                 piero
#
# $Id: Makefile,v 1.12 1997/06/09 22:27:11 max Exp $
#

DISTNAME=       xanim27070
PKGNAME=        xanim-2.70.7.0
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://xanim.va.pubnix.com/ \
		ftp://xanim.va.pubnix.com/modules/
DISTFILES=	${EXTRACT_ONLY} ${EXTRA_FILES}

MAINTAINER=	ports@FreeBSD.ORG

EXTRACT_ONLY=   ${DISTNAME}.tar.gz
EXTRA_FILES=    xa2.0_cvid_netbsd386.o.Z xa2.0_iv32_netbsd386.o.Z \
		xa1.0_cyuv_netbsd386.o.Z
USE_IMAKE=	yes
MAN1=		xanim.1
MANCOMPRESSED=	yes

post-extract:
	@for file in ${EXTRA_FILES}; do \
	  ${CP} ${DISTDIR}/$$file ${WRKSRC}; \
	  uncompress ${WRKSRC}/$$file; \
	done
	${CP} ${WRKSRC}/docs/xanim.man ${WRKSRC}

.include <bsd.port.mk>
