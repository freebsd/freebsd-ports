# Created by: ijliao
# $FreeBSD$

PORTNAME=	libyahoo2
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C library that handles the new Yahoo! Messenger protocol

USES=		libtool pathfix ssl:build tar:bzip2
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

post-patch:
	@${REINPLACE_CMD} -e 's|-Wall -ansi -pedantic||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-g -Wall||g ; \
		 s| -module ||g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
