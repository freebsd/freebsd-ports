# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	jive
PORTVERSION=	1.1
CATEGORIES=	misc
MASTER_SITES=	LOCAL/obrien ftp://nuxi.ucdavis.edu/pub/misc/

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Filter that converts English text to Jive

CONFLICTS=	filters-2* talkfilters-2*

WRKSRC=		${WRKDIR}/jive
MAKE_ARGS+=	CC=${CC:Q} CFLAGS=${CFLAGS:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jive ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/jive.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
