# ex:ts=8
# Ports collection makefile for:	libyahoo2
# Date created:			Apr 6, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libyahoo2
PORTVERSION=	0.7.7
CATEGORIES=	net-im
MASTER_SITES=	SF

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	A C library that handles the new Yahoo! Messenger protocol

USE_AUTOTOOLS=	libtool:22
USE_BZIP2=	yes
USE_GNOME=	glib20 gnomehack gnometarget
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-Wall -ansi -pedantic||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-g -Wall||g ; \
		 s| -module ||g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
