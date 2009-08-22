# New ports collection makefile for:	tivodecode
# Date created:		2007-01-01
# Whom:			Yi-Hsuan Hsin <mhsin@mhsin.org>
#
# $FreeBSD$
#

PORTNAME=	tivodecode
DISTVERSION=	0.2pre4
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.2pre4

MAINTAINER=	mhsin@mhsin.org
COMMENT=	Converts .TiVo files to normal MPEG files

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
