# Created by: ijliao
# $FreeBSD$

PORTNAME=	mpgtx
PORTVERSION=	1.3.1
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	SF

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Command line MPEG audio/video/system file toolbox

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
ALL_TARGET=	default

pre-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS=|CFLAGS\+=|g ; \
		 s|="\$$cflags \$$optimization_cflags|+="${CFLAGS}|g ; \
		 s|g++|${CXX}|g; s|-pedantic||' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mpgtx ${STAGEDIR}${PREFIX}/bin
.for link in mpgcat mpgdemux mpginfo mpgjoin mpgsplit tagmp3
	${LN} -sf mpgtx ${STAGEDIR}${PREFIX}/bin/${link}
.endfor
	${INSTALL_MAN} ${WRKSRC}/man/mpgtx.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/tagmp3.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
