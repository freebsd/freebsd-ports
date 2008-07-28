# New ports collection makefile for:    tintin++
# Date created:         15 Nov 1994
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	tintin
PORTVERSION=	1.98.3
CATEGORIES+=	net games
MASTER_SITES=	SFE

MAINTAINER=	sunpoet@sunpoet.net
COMMENT=	A client program to help playing MUDs (devel version)

LATEST_LINK=	${PORTNAME}-devel

WRKSRC=		${WRKDIR}/tt/src

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/tt++

.include <bsd.port.pre.mk>

DOCS=		BUGS CREDITS FAQ README TODO \
		docs/chat_protocol.txt docs/tintin19.txt
PORTDOCS=	${DOCS:T}

post-configure:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tt++ ${PREFIX}/bin

post-install:
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC}/.. && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
