# $FreeBSD$

PORTNAME=	spglib
DISTVERSIONPREFIX=	v
DISTVERSION=	1.15.1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C library for finding and handling crystal symmetries

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf libtool # cmake is also available now, but the header path change breaks dependencies
USE_GITHUB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
