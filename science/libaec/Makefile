# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libaec
PORTVERSION=	1.0.4
CATEGORIES=	science
MASTER_SITES=	https://gitlab.dkrz.de/k202009/libaec/uploads/ea0b7d197a950b0c110da8dfdecbb71f/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Adaptive entropy coding library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/Copyright.txt

USES=		libtool

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	hdf-szip

.include <bsd.port.mk>
