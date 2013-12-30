# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	uplog
PORTVERSION=	0.3
CATEGORIES=	net
MASTER_SITES=	http://www.nerdlabs.org/downloads/${PORTNAME}/

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	UDP-based ping program

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include

PORTDOCS=	README
PLIST_FILES=	bin/uplog

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e \
	's|#include <malloc.h>||g' \
		${WRKSRC}/${PORTNAME}.c

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
