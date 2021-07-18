# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	libaec
PORTVERSION=	1.0.5
CATEGORIES=	science
MASTER_SITES=	https://gitlab.dkrz.de/k202009/libaec/uploads/eb02f9727d538283d1730fdf8fd85665/

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
