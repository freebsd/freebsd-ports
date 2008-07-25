# New ports collection makefile for:    tintin++
# Date created:         15 Nov 1994
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	tintin
PORTVERSION=	1.98.1
PORTREVISION=	1
CATEGORIES+=	net games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER?=	sunpoet@sunpoet.net
COMMENT=	A client program to help playing muds (devel version)

LATEST_LINK=	${PORTNAME}-devel

WRKSRC=		${WRKDIR}/tt/src

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/tt++
PORTDOCS=	BUGS CREDITS FAQ README TODO chat_protocol.txt tintin19.txt

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tt++ ${PREFIX}/bin
.ifndef NOPORTDOCS
	${MKDIR} ${DOCSDIR}
.for i in BUGS CREDITS FAQ README TODO docs/chat_protocol.txt docs/tintin19.txt
	${INSTALL_DATA} ${WRKSRC}/../${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
