# New ports collection makefile for:    tintin++
# Date created:         15 Nov 1994
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	tintin
PORTVERSION=	1.95.7
CATEGORIES+=	net games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER?=	ports@FreeBSD.org
COMMENT=	A client program to help playing muds (devel version)

LATEST_LINK=	${PORTNAME}-devel

WRKSRC=		${WRKDIR}/tt/src

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/tt++
PORTDOCS=	BUGS CREDITS FAQ README TODO tintin19.txt chat_protocol.txt

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
LIB_DEPENDS+=	readline.5:${PORTSDIR}/devel/readline
CFLAGS+=	-I ${LOCALBASE}/include
MAKE_ENV+=	LIBS="-L${LOCALBASE}/lib"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tt++ ${PREFIX}/bin
.ifndef NOPORTDOCS
	${MKDIR} ${DOCSDIR}
.for i in FAQ README TODO CREDITS BUGS docs/tintin19.txt docs/chat_protocol.txt
	${INSTALL_DATA} ${WRKSRC}/../${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
