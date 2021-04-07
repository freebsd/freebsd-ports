PORTNAME=	dymo-cups-drivers
PORTVERSION=	1.4.0
PORTREVISION=	4
CATEGORIES=	print
MASTER_SITES=	http://download.dymo.com/Software/Linux/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Open source DYMO CUPS driver

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcupsimage.so:print/cups

WRKSRC=		${WRKDIR}/dymo-cups-drivers-1.4.0.5

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
