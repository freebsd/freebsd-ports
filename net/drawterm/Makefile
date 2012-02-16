# New ports collection makefile for:	drawterm
# Date created:	January 07, 2012
# Whom:		Winston Weinert <winstonw@lavabit.com>
#
# $FreeBSD$
#

PORTNAME=	drawterm
PORTVERSION=	20110822
CATEGORIES=	net
MASTER_SITES=	http://swtch.com/drawterm/
EXTRACT_SUFX=	.tgz

MAINTAINER=	winstonw@lavabit.com
COMMENT=	Plan9 cpu client

USE_XORG=	x11 xt

PLIST_FILES=	bin/drawterm
PORTDOCS=	LICENSE README
WRKSRC=		${WRKDIR}/${PORTNAME}

MAKE_ARGS=	CONF=pthread

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/drawterm ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${WRKSRC}/LICENSE ${DOCSDIR}
.endif

.include <bsd.port.mk>
