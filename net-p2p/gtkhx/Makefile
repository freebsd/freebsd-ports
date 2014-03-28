# Created by: Josh Elsasser <jre@vineyard.net>
# $FreeBSD$

PORTNAME=	gtkhx
PORTVERSION=	0.9.4
PORTREVISION=	6
CATEGORIES=	net-p2p
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+ version of Hx, a UNIX Hotline Client

USES=		pathfix gmake
USE_GNOME=	gdkpixbuf
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		gtkhx.1

NO_STAGE=	yes

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=""
USES+=		gettext
.else
PLIST_SUB+=	NLS="@comment "
CONFIGURE_ARGS+=--disable-nls
.endif

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
