# New ports collection makefile for:	libbt
# Date created:				Feb 26 2004
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	libbt
PORTVERSION=	1.05
PORTREVISION=	2
CATEGORIES=	net-p2p devel
MASTER_SITES=	SF

MAINTAINER=	flz@FreeBSD.org
COMMENT=	C library implementing the core BitTorrent protocol

LIB_DEPENDS=	curl.5:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GCC=	3.4
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

PORTDOCS=	protocol-ext.txt protocol.txt

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|depend||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|\(CFLAGS:=\)|\1\@CFLAGS\@ \@CPPFLAGS\@ |' ${WRKSRC}/src/Makefile.in

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/libbt.a ${PREFIX}/lib
	${MKDIR} ${PREFIX}/include/libbt
.for i in btcheck btget btlist
	${INSTALL_PROGRAM} ${WRKSRC}/src/${i} ${PREFIX}/bin
.endfor
.for i in benc.h bitset.h bterror.h btmessage.h bts.h context.h peer.h random.h segmenter.h strbuf.h stream.h types.h util.h
	${INSTALL_DATA} ${WRKSRC}/include/${i} ${PREFIX}/include/libbt
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/docs/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
