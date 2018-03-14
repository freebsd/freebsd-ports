# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libaec
PORTVERSION=	1.0.2
DISTVERSIONPREFIX=	v
CATEGORIES=	science
MASTER_SITES=	LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Adaptive entropy coding library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/Copyright.txt

CONFLICTS_INSTALL=	hdf-szip

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USES=		autoreconf libtool tar:bz2

GL_ACCOUNT=	k202009
GL_COMMIT=	b428510436e86c34908e3cb00a6b2e62aa1390da
GL_SITE=	https://gitlab.dkrz.de/
USE_GITLAB=	yes

.include <bsd.port.mk>
