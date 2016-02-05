# Created by: Michael Handler <handler@grendel.net>
# $FreeBSD$

PORTNAME=	ccxstream
PORTVERSION=	1.0.15
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF/xbplayer/XStream%20Servers/ccXStream%20${PORTVERSION}%20for%20Linux

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Stream media files to XBox Media Center via XBMSP

USES=		gmake ncurses readline
USE_RC_SUBR=	ccxstream

PLIST_FILES=	bin/ccxtest \
		sbin/ccxstream
PORTDOCS=	README ChangeLog TODO xbmsp-xml.txt xbmsp.txt

OPTIONS_DEFINE=	SO_KEEPALIVE TCP_NODELAY DOCS
OPTIONS_DEFAULT=SO_KEEPALIVE
SO_KEEPALIVE_DESC=	Build with SO_KEEPALIVE
SO_KEEPALICE_CFLAGS=	-DSO_KEEPALIVE
TCP_NODELAY_DESC=	Build with TCP_NODELAY
TCP_NODELAY_CFLAGS=	-DTCP_NODELAY

post-patch:
	@${REINPLACE_CMD} -e 's|-ltermcap|-lncurses|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ccxstream ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/ccxtest ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
