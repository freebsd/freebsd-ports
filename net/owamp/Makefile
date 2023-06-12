PORTNAME=	owamp
PORTVERSION=	3.3
CATEGORIES=	net
MASTER_SITES=	http://software.internet2.edu/sources/owamp/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Implementation of the One-Way Active Measurement Protocol
WWW=		https://www.internet2.edu/performance/owamp/

LICENSE=	APACHE20

GNU_CONFIGURE=	yes

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

.include <bsd.port.mk>
