PORTNAME=	yencode
PORTVERSION=	0.46
PORTREVISION=	8
CATEGORIES=	news
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free (GPL) encoder and decoder for the yEnc Usenet file format
WWW=		http://www.yencode.org/

USES=		gettext
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
