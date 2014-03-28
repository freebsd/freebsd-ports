# Created by: Florent Thoumie <flz@xbsd.org>
# $FreeBSD$

PORTNAME=	libbt
PORTVERSION=	1.05
PORTREVISION=	4
CATEGORIES=	net-p2p devel
MASTER_SITES=	SF

MAINTAINER=	flz@FreeBSD.org
COMMENT=	C library implementing the core BitTorrent protocol

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=	yes
USES=		gmake
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	protocol-ext.txt protocol.txt

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|depend||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|\(CFLAGS:=\)|\1\@CFLAGS\@ \@CPPFLAGS\@ |' ${WRKSRC}/src/Makefile.in

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/libbt.a ${STAGEDIR}${PREFIX}/lib
	${MKDIR} ${STAGEDIR}${PREFIX}/include/libbt
.for i in btcheck btget btlist
	${INSTALL_PROGRAM} ${WRKSRC}/src/${i} ${STAGEDIR}${PREFIX}/bin
.endfor
.for i in benc.h bitset.h bterror.h btmessage.h bts.h context.h peer.h random.h segmenter.h strbuf.h stream.h types.h util.h
	${INSTALL_DATA} ${WRKSRC}/include/${i} ${STAGEDIR}${PREFIX}/include/libbt
.endfor

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/docs/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
