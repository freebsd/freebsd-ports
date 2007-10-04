# New ports collection makefile for:	tivodecode
# Date created:		2007-01-01
# Whom:			Yi-Hsuan Hsin <mhsin@mhsin.org>
#
# $FreeBSD$
#

PORTNAME=	tivodecode
DISTVERSION=	0.1.4
CATEGORIES=	multimedia
MASTER_SITES=	SF

MAINTAINER=	mhsin@mhsin.org
COMMENT=	Converts .TiVo files to normal MPEG files

USE_GMAKE=	yes

post-patch:
	${REINPLACE_CMD} -e 's/CFLAGS=/CFLAGS+=/' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/objects.dir/tivodecode ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
