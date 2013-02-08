# Created by: ache
# $FreeBSD$

PORTNAME=	tintin++
PORTVERSION=	2.00.9
CATEGORIES+=	net games
MASTER_SITES=	SF/tintin/TinTin%2B%2B%20Source%20Code/${PORTVERSION}/
DISTNAME=	tintin-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A client program to help playing MUDs

LICENSE=	GPLv2

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre

OPTIONS_DEFINE=	BIG5 DOCS
BIG5_DESC=	Big5 support

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

SLAVEDIRS=	chinese/tintin++

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBIG5}
CONFIGURE_ARGS+=--enable-big5
.endif

post-configure:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tt++ ${PREFIX}/bin/
.if ${PORT_OPTIONS:MDOCS}
	${INSTALL} -d ${DOCSDIR}/
	cd ${WRKSRC}/../ && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
