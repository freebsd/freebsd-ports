# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ip2proxy
PORTVERSION=	20200722
CATEGORIES=	net

MAINTAINER=	zi@FreeBSD.org
COMMENT=	C library to lookup proxies

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	ip2location
GH_PROJECT=	${PORTNAME}-c
GH_TAGNAME=	4ce220b

USES=		autoreconf libtool
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

post-install:
	(cd ${WRKSRC} && ${MAKE} install-data DESTDIR=${STAGEDIR})

.include <bsd.port.mk>
