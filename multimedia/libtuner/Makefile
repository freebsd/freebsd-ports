# Created by: Jason Harmening <jason.harmening@gmail.com>
# $FreeBSD$

PORTNAME=	libtuner
PORTVERSION=	1.1.3
CATEGORIES=	multimedia
MASTER_SITES=	ftp://corona.homeunix.net/ports/libtuner/

MAINTAINER=	jason.harmening@gmail.com
COMMENT=	Userspace drivers for various TV/radio tuner ICs

LICENSE=	BSD2CLAUSE MIT
LICENSE_COMB=	multi

BROKEN_powerpc64=	fails to compile: tuner_iic_device.cpp: EINVAL was not declared in this scope

MAKE_ARGS+=	INSTALLDIR=${STAGEDIR}${PREFIX}
MAKE_ARGS+= 	-D LIBTUNER_ENABLE_IIC
USE_LDCONFIG=	${PREFIX}/lib/libtuner

.include <bsd.port.mk>
