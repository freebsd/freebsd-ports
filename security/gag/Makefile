# ex:ts=8
# Ports collection makefile for:  gag
# Version required: 0.0
# Date created:			  Sun Feb 12, 2000
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

DISTNAME=	sickenscan
PKGNAME=	gag-2.9
CATEGORIES=	security
MASTER_SITES=	http://staff.washington.edu/dittrich/misc/
EXTRACT_SUFX=	.tar

MAINTAINER=	obrien@FreeBSD.org

ALL_TARGET=	gag

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/gag ${PREFIX}/sbin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/gag
	@${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/gag
.endif

.include <bsd.port.mk>
