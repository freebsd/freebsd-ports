# ex:ts=8
# New ports collection makefile for:	rascal
# Date created:			Apr 9, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rascal
PORTVERSION=	0.1.2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ijliao@FreeBSD.org

USE_BISON=	yes

USE_GMAKE=	yes
ALL_TARGET=	

DOCS=	modules.pdf modules.ps rascal.pdf rascal.ps

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/rascal ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/rascal
.for file in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/rascal
.endfor
.endif

.include <bsd.port.mk>
