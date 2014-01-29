# Created by: ache
# $FreeBSD$

PORTNAME=	tintin++
PORTVERSION=	2.01.0
CATEGORIES+=	net games
MASTER_SITES=	SF/tintin/TinTin%2B%2B%20Source%20Code/${PORTVERSION}/
DISTNAME=	tintin-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Client program to help playing MUDs

LICENSE=	GPLv2

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

OPTIONS_DEFINE=	BIG5 DOCS
BIG5_DESC=	Big5 support

CONFIGURE_ARGS=	--includedir=${LOCALBASE}/include \
		--libdir=${LOCALBASE}/lib \
		--prefix=${PREFIX}
CONFIGURE_ENV=	ac_cv_file__dev_ptmx=no
CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
USES=		gmake
WRKSRC=		${WRKDIR}/tt/src

DOCS=		CREDITS FAQ README SCRIPTS TODO \
		docs/chat_protocol.txt docs/tintin19.txt
PLIST_FILES=	bin/tt++
PORTDOCS=	${DOCS:T}

SLAVEDIRS=	chinese/tintin++

BIG5_CONFIGURE_ARGS=	--enable-big5

post-configure:
	@${REINPLACE_CMD} -e 's|-lpthread|-pthread|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tt++ ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/../ && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
