# New ports collection makefile for:	keyprint
# Date created:		Sat May 29 02:05:00 PDT 1999
# Whom:			mharo@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	keyprint
PORTVERSION=	1.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	mharo

MAINTAINER=	mharo@FreeBSD.org
COMMENT=	Print S/Key keys on a piece of paper, twice the size of a credit card

NO_BUILD=	yes
USE_REINPLACE=	yes

post-patch:
	${REINPLACE_CMD} -e 's,__PREFIX__,${PREFIX},' ${WRKSRC}/keyprint

do-install:
	${MKDIR} ${PREFIX}/share/keyprint
	${INSTALL_DATA} ${WRKSRC}/keyblank.ps ${PREFIX}/share/keyprint
	${INSTALL_SCRIPT} ${WRKSRC}/keyprint ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/keyprint
.endif

.include <bsd.port.mk>
