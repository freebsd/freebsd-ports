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

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e \
	's|#include <malloc.h>||g' \
		${WRKSRC}/${PORTNAME}.c

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
