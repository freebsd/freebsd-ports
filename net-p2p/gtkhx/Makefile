# New ports collection makefile for:   gtkhx
# Date created:        9 February 2002
# Whom:                Josh Elsasser <jre@vineyard.net>
#
# $FreeBSD$
#

PORTNAME=	gtkhx
PORTVERSION=	0.9.4
PORTREVISION=	2
CATEGORIES=	net-p2p
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GTK+ version of Hx, a UNIX Hotline Client

USE_GNOME=	gdkpixbuf gnomehack gnometarget
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gtkhx.1

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
PLIST_SUB+=	NLS=""
USE_GETTEXT=	yes
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

.include <bsd.port.post.mk>
