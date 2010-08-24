# New ports collection makefile for:    tintin++
# Date created:         15 Nov 1994
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	tintin++
PORTVERSION=	2.00.1
CATEGORIES+=	net games
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	tintin-${PORTVERSION}

MAINTAINER=	sunpoet@sunpoet.net
COMMENT=	A client program to help playing MUDs

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

CONFIGURE_ARGS+=--includedir=${LOCALBASE}/include --libdir=${LOCALBASE}/lib \
		--prefix=${PREFIX}
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}"
GNU_CONFIGURE=	yes
PLIST_FILES=	bin/tt++
PORTDOCS=	${DOCS:T}
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/tt/src

DOCS=		CREDITS FAQ README SCRIPTS TODO \
		docs/chat_protocol.txt docs/tintin19.txt
PROJECTHOST=	tintin-mud-client

.include <bsd.port.pre.mk>

post-configure:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tt++ ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC}/.. && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
