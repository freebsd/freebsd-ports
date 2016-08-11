# Created by: Jason Harmening <jason.harmening@gmail.com>
# $FreeBSD$

PORTNAME=	libtuner
PORTVERSION=		1.1.3
CATEGORIES=	multimedia
MASTER_SITES=	ftp://corona.homeunix.net/ports/libtuner/

MAINTAINER=	jason.harmening@gmail.com
COMMENT=	Userspace drivers for various TV/radio tuner ICs

LICENSE=	BSD2CLAUSE MIT
LICENSE_COMB=	multi

MAKE_ARGS+=	INSTALLDIR=${STAGEDIR}${PREFIX}
USE_LDCONFIG=	${PREFIX}/lib/libtuner

.include <bsd.port.options.mk>

.if (${OSVERSION} >= 1002502)
MAKE_ARGS+= 		-D LIBTUNER_ENABLE_IIC
.endif

.include <bsd.port.mk>
