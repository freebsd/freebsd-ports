# New ports collection makefile for:	add
# Date created:				20 August 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	add
PORTVERSION=	20021229
CATEGORIES=	math
MASTER_SITES=	ftp://dickey.his.com/add/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Full-screen editing calculator

WRKSRC=		${WRKDIR}/${PORTNAME}-t${PORTVERSION}

GNU_CONFIGURE=	yes
MAKEFILE=	makefile

MAN1=		add.1
PORTDOCS=	CHANGES README
PLIST_FILES=	bin/add %%DATADIR%%/add.hlp
PLIST_DIRS=	%%DATADIR%%

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/add ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/add.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/add.hlp ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in CHANGES README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
