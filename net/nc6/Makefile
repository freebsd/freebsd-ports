# Created by: Filippo Natali <filippo@widestore.net>
# $FreeBSD$

PORTNAME=	nc6
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.deepspace6.net/pub/ds6/sources/nc6/ \
		http://ftp.deepspace6.net/pub/ds6/sources/nc6/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Netcat clone with IPv6 support

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2014-03-10

USES=		iconv
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS

NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--disable-nls

.include <bsd.port.mk>
