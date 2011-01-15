# New ports collection makefile for:    tintin++
# Date created:         15 Nov 1994
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	tintin++
PORTVERSION=	2.00.5
CATEGORIES+=	net games
MASTER_SITES=	SF/tintin/TinTin%2B%2B%20Source%20Code/${PORTVERSION}/
DISTNAME=	tintin-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A client program to help playing MUDs

LICENSE=	GPLv2

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

CONFIGURE_ARGS+=--includedir=${LOCALBASE}/include --libdir=${LOCALBASE}/lib \
		--prefix=${PREFIX}
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		ac_cv_file__dev_ptmx=no
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/tt/src

DOCS=		CREDITS FAQ README SCRIPTS TODO \
		docs/chat_protocol.txt docs/tintin19.txt
PLIST_FILES=	bin/tt++
PORTDOCS=	${DOCS:T}

post-configure:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tt++ ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC}/.. && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
