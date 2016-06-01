# Created by: Fabian Keil <fk@fabiankeil.de>
# $FreeBSD$

PORTNAME=	obfsclient
PORTVERSION=	0.0.2
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	security

MAINTAINER=	fk@fabiankeil.de
COMMENT=	Tor-managed pluggable transport client

LIB_DEPENDS=	liballium-1.0.so:devel/liballium \
		libevent.so:devel/libevent2

USE_GITHUB=	yes
GH_ACCOUNT=	Yawning

GNU_CONFIGURE=	yes
USES=		autoreconf compiler:c++11-lib pkgconfig tar:bzip2

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	COPYING

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${STAGEDIR}${DOCSDIR}

regression-test: build
	(cd ${WRKSRC} && make check)

.include <bsd.port.mk>
