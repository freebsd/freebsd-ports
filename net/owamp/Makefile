PORTNAME=	owamp
PORTVERSION=	3.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://software.internet2.edu/sources/owamp/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Implementation of the One-Way Active Measurement Protocol
WWW=		https://www.internet2.edu/performance/owamp/

LICENSE=	APACHE20

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=int-conversion
.endif

.include <bsd.port.mk>
