# New ports collection makefile for:    tintin++
# Date created:         15 Nov 1994
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	tintin++
PORTVERSION=	2.00.8
PORTREVISION=	1
CATEGORIES+=	net games
MASTER_SITES=	SF/tintin/TinTin%2B%2B%20Source%20Code/${PORTVERSION}/
DISTNAME=	tintin-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A client program to help playing MUDs

LICENSE=	GPLv2

LIB_DEPENDS=	pcre.1:${PORTSDIR}/devel/pcre

OPTIONS=	BIG5 "Big5 support" off

CONFIGURE_ARGS=	--includedir=${LOCALBASE}/include \
		--libdir=${LOCALBASE}/lib \
		--prefix=${PREFIX}
CONFIGURE_ENV=	ac_cv_file__dev_ptmx=no
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/tt/src

DOCS=		CREDITS FAQ README SCRIPTS TODO \
		docs/chat_protocol.txt docs/tintin19.txt
PLIST_FILES=	bin/tt++
PORTDOCS=	${DOCS:T}

.include <bsd.port.options.mk>

.if defined(WITH_BIG5)
CONFIGURE_ARGS+=--enable-big5
.endif

post-configure:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tt++ ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${INSTALL} -d ${DOCSDIR}/
	cd ${WRKSRC}/../ && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
