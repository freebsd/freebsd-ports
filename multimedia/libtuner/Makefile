PORTNAME=	libtuner
PORTVERSION=	1.1.5
CATEGORIES=	multimedia
MASTER_SITES=	ftp://corona.homeunix.net/ports/libtuner/

MAINTAINER=	jah@FreeBSD.org
COMMENT=	Userspace drivers for various TV/radio tuner ICs

LICENSE=	BSD2CLAUSE MIT
LICENSE_COMB=	multi

USES=		uidfix
USE_LDCONFIG=	${PREFIX}/lib/libtuner

MAKE_ARGS+=	-D LIBTUNER_ENABLE_IIC

.include <bsd.port.mk>
