# New ports collection makefile for:	mpgtx
# Date created:			May 15, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mpgtx
PORTVERSION=	1.3.1
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	SF

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	A command line MPEG audio/video/system file toolbox

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
ALL_TARGET=	default

MAN1=	mpgtx.1 tagmp3.1
MLINKS=	mpgtx.1 mpgcat.1 \
	mpgtx.1 mpgdemux.1 \
	mpgtx.1 mpginfo.1 \
	mpgtx.1 mpgjoin.1 \
	mpgtx.1 mpgsplit.1

.include <bsd.port.pre.mk>

pre-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS=|CFLAGS\+=|g ; \
		 s|="\$$cflags \$$optimization_cflags|+="${CFLAGS}|g ; \
		 s|g++|${CXX}|g; s|-pedantic||' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mpgtx ${PREFIX}/bin
.for link in mpgcat mpgdemux mpginfo mpgjoin mpgsplit tagmp3
	${LN} -sf mpgtx ${PREFIX}/bin/${link}
.endfor
	${INSTALL_MAN} ${WRKSRC}/man/mpgtx.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/tagmp3.1 ${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
