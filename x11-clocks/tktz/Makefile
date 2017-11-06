# Created by: Alexander Gromnizki
# $FreeBSD$

PORTNAME=	tktz
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	x11-clocks tk
MASTER_SITES=	http://gromnizki.unixdev.net/soft/

MAINTAINER=	gromnizki@unixdev.net
COMMENT=	Tcl/Tk-based timezone viewer

USES=		tk:85+,run
NO_BUILD=	yes

post-patch:
	${REINPLACE_CMD} -e 's|%%TK_VER%%|${TK_VER}|' ${WRKSRC}/tktz

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/tktz
	${INSTALL_SCRIPT} ${WRKSRC}/tktz ${STAGEDIR}${PREFIX}/lib/tktz
	${LN} -sf ${PREFIX}/lib/tktz/tktz ${STAGEDIR}${PREFIX}/bin
.for file in tktz.help README LICENSE NEWS
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/lib/tktz
.endfor

.include <bsd.port.mk>
