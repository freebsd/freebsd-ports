PORTNAME=	openscop
PORTVERSION=	0.9.7
CATEGORIES=	math

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Library for Data Exchange in Polyhedral Compilation Tools
WWW=		https://github.com/periscop/openscop

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		autoreconf gmake libtool

USE_GITHUB=	yes
GH_ACCOUNT=	periscop

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS+=	--with-gmp-prefix=${LOCALBASE}

.include <bsd.port.mk>
