# New ports collection makefile for:	wmfuzzy
# Date created:			4 August 2002
# Whom:				Adam Weinberger <adam@vectors.cx>
#
# $FreeBSD$
#

PORTNAME=	wmfuzzy
PORTVERSION=	0.5
CATEGORIES=	x11-clocks windowmaker
MASTER_SITES=	http://www.manicai.net/comp/wmfuzzy/
EXTRACT_SUFX=	.tgz

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	A fuzzy clock WindowMaker dockapp

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_X_PREFIX=	yes
USE_XPM=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/wmfuzzy ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/../README ${DOCSDIR}
.endif

.include <bsd.port.mk>
