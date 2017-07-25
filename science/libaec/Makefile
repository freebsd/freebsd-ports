# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libaec
PORTVERSION=	1.0.1
CATEGORIES=	science
MASTER_SITES=	https://gitlab.dkrz.de/k202009/libaec/repository/archive.tar.bz2?ref=v${PORTVERSION}&dummy=/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Adaptive entropy coding library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/Copyright.txt

CONFLICTS_INSTALL=	hdf-szip

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USES=		autoreconf libtool tar:bz2

GL_TAGNAME=	d808db1e1276f6c23feccdcefd56f7e38e2d7c9e
WRKSRC=		${WRKDIR}/${PORTNAME}-v${PORTVERSION}-${GL_TAGNAME}

.include <bsd.port.mk>
