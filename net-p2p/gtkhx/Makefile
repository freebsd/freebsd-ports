# Created by: Josh Elsasser <jre@vineyard.net>
# $FreeBSD$

PORTNAME=	gtkhx
PORTVERSION=	0.9.4
PORTREVISION=	8
CATEGORIES=	net-p2p
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+ version of Hx, a UNIX Hotline Client

LICENSE=	GPLv2

USES=		pathfix gmake
USE_GNOME=	gdkpixbuf
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-I/usr/local/include||g ; \
		 s|-L/usr/local/lib||g ; \
		 s|^mandir =.*$$|mandir = $${prefix}/man/man1|g'
	@${REINPLACE_CMD} -e 's|^CC =|#CC =|g' ${WRKSRC}/plugins/eliza/Makefile
	@${REINPLACE_CMD} -e 's|^CC=|#CC=|g ; \
		 s|$$CFLAGS -O2|$$CFLAGS|g ; \
		 s|-g -Wall|$$CFLAGS -Wall|g' ${WRKSRC}/configure

.include <bsd.port.mk>
