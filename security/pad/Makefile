# New ports collection makefile for:	pad
# Date created:				8 July 2000
# Whom:					Trevor Johnson
#
# $FreeBSD$
#

PORTNAME=	pad
PORTVERSION=	0.7
CATEGORIES=	security
MASTER_SITES=	http://www.lammah.com/pad/
EXTRACT_SUFX=	.tgz

MAINTAINER=	trevor@jpj.net

DOC_FILES=	COPYING README ChangeLog
GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pad ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/pad
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/pad
.endfor
.endif

.include <bsd.port.mk>
