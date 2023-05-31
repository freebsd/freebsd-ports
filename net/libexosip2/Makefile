PORTNAME=	libeXosip2
PORTVERSION=	5.3.0
CATEGORIES=	net
MASTER_SITES=	SAVANNAH/exosip
DISTNAME=	${PORTNAME:tl}-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	GPL library that extends the capability of the oSIP library
WWW=		https://savannah.nongnu.org/projects/exosip

LICENSE=	GPLv2

LIB_DEPENDS=	libosip2.so:net/libosip2

USES=		libtool ssl
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	libeXosip2-legacy

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
SHLIB_VER=	15

PLIST_SUB+=	SHLIB_VER=${SHLIB_VER}

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

.include <bsd.port.mk>
