# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	uplog
PORTVERSION=	0.3
CATEGORIES=	net
MASTER_SITES=	http://www.nerdlabs.org/downloads/${PORTNAME}/

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	UDP-based ping program

BROKEN=		unfetchable

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

PORTDOCS=	README
PLIST_FILES=	bin/uplog

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e \
	's|#include <malloc.h>||g' \
		${WRKSRC}/${PORTNAME}.c

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
