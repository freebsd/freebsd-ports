# New ports collection makefile for:	pad
# Date created:				8 July 2000
# Whom:					Trevor Johnson
#
# $FreeBSD$
#

PORTNAME=	pad
PORTEPOCH=	1
PORTVERSION=	0.7
CATEGORIES=	security
MASTER_SITES=	http://www.lammah.com/pad/
EXTRACT_SUFX=	.tgz

MAINTAINER=	trevor@FreeBSD.org

DOC_FILES=	COPYING README ChangeLog
GNU_CONFIGURE=	yes
USE_OPENSSL=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pad ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
