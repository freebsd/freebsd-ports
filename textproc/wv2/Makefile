# Created by: lofi@FreeBSD.org
# $FreeBSD$

PORTNAME=	wv2
PORTVERSION=	0.4.2
PORTREVISION=	8
CATEGORIES=	textproc
MASTER_SITES=	SF/wvware/

MAINTAINER=	salvadore@FreeBSD.org
COMMENT=	Library providing routines to access Microsoft Word files

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

USES=		cmake gnome iconv libtool pkgconfig tar:bzip2
USE_GNOME=	libgsf
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|glib/giochannel.h|glib.h|g' \
		${WRKSRC}/src/olestream.h

.include <bsd.port.mk>
