# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libaec
PORTVERSION=	1.0.4
DISTVERSIONPREFIX=	v
CATEGORIES=	science
MASTER_SITES=	https://gitlab.dkrz.de/k202009/libaec/-/archive/v${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Adaptive entropy coding library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/Copyright.txt

USES=		autoreconf libtool tar:bz2

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	hdf-szip

.include <bsd.port.mk>
