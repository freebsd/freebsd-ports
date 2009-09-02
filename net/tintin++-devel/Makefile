# New ports collection makefile for:    tintin++
# Date created:         15 Nov 1994
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	tintin
PORTVERSION=	1.99.6
CATEGORIES+=	net games
MASTER_SITES=	SF/${PORTNAME}/TinTin%2B%2B%20Source%20Code/${PORTVERSION}

MAINTAINER=	sunpoet@sunpoet.net
COMMENT=	A client program to help playing MUDs (devel version)

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

CONFIGURE_ARGS+=	--prefix=${PREFIX} --includedir=${LOCALBASE}/include \
			--libdir=${LOCALBASE}/lib
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}"

LATEST_LINK=	${PORTNAME}-devel

WRKSRC=		${WRKDIR}/tt/src

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/tt++

DOCS=		CREDITS FAQ README SCRIPTS TODO \
		docs/chat_protocol.txt docs/tintin19.txt
PORTDOCS=	${DOCS:T}

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
