PORTNAME=	dymo-cups-drivers
PORTVERSION=	1.4.0
PORTREVISION=	4
CATEGORIES=	print
MASTER_SITES=	https://download.dymo.com/Software/Linux/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source DYMO CUPS driver
WWW=		https://www.dymo.com/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcupsimage.so:print/cups

USES=		localbase:ldflags
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/dymo-cups-drivers-1.4.0.5

.include <bsd.port.mk>
