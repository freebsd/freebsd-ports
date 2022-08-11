PORTNAME=	mod_scgi
PORTVERSION=	2.0
CATEGORIES=	www
MASTER_SITES=	http://python.ca/scgi/releases/
DISTNAME=	scgi-${PORTVERSION:S/.a/a/}

MAINTAINER=	w.schwarzenfeld@utanet.at
COMMENT=	Apache module that implements the client side of the SCGI protocol

LICENSE=	MIT
LICENSE_FILE=	${WRKDIR}/${DISTNAME}/LICENSE.txt

USES=		apache:2.4

SCGI_DIR=	apache2
WRKSRC=		${WRKDIR}/${DISTNAME}/${SCGI_DIR}

AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

.include <bsd.port.mk>
