# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libaec
PORTVERSION=	1.0.4
CATEGORIES=	science
MASTER_SITES=	LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Adaptive entropy coding library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/Copyright.txt

CONFLICTS_INSTALL=	hdf-szip

USES=		autoreconf libtool tar:bz2

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

GL_ACCOUNT=	k202009
GL_COMMIT=	0c0453a0e463da9c2183f46d0255f05645e0e5ef
GL_SITE=	https://gitlab.dkrz.de/
USE_GITLAB=	yes

.include <bsd.port.mk>
