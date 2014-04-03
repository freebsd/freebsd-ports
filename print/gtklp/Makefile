# Created by: Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
# $FreeBSD$

PORTNAME=	gtklp
PORTVERSION=	1.2.9
PORTREVISION=	1
DISTVERSIONSUFFIX=	.src
CATEGORIES=	print
MASTER_SITES=	SF

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	GTK interface to cups

LIB_DEPENDS=	libcups.so:${PORTSDIR}/print/cups-client

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		gettext pkgconfig
USE_GNOME=	gtk20
USE_OPENSSL=	yes
USE_AUTOTOOLS=	automake:env
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -D_IPP_PRIVATE_STRUCTURES
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
