# New ports collection makefile for:	pad
# Date created:				8 July 2000
# Whom:					Trevor Johnson
#
# $FreeBSD$
#

PORTNAME=	pad
PORTVERSION=	0.5
CATEGORIES=	security
MASTER_SITES=	http://www.lammah.com/pad/
EXTRACT_SUFX=	.tgz

MAINTAINER=	trevor@jpj.net

post-extract:
	@${RM} ${WRKSRC}/install-sh ${WRKSRC}/mkinstalldirs \
	${WRKSRC}/missing ${WRKSRC}/INSTALL ${WRKSRC}/COPYING
	@${TOUCH} ${WRKSRC}/install-sh ${WRKSRC}/mkinstalldirs \
	${WRKSRC}/missing ${WRKSRC}/INSTALL ${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USE_AUTOMAKE=	yes
USE_GMAKE=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/pad
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/pad
.endif

.include <bsd.port.mk>
