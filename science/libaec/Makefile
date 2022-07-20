PORTNAME=	libaec
PORTVERSION=	1.0.6
CATEGORIES=	science
MASTER_SITES=	https://gitlab.dkrz.de/k202009/libaec/uploads/45b10e42123edd26ab7b3ad92bcf7be2/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Adaptive entropy coding library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		libtool

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	hdf-szip

.include <bsd.port.mk>
