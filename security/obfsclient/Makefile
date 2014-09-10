# Created by: Fabian Keil <fk@fabiankeil.de>
# $FreeBSD$

PORTNAME=	obfsclient
PORTVERSION=	0.0.2
PORTREVISION=	1
CATEGORIES=	security
DISTNAME=	g-${GH_ACCOUNT}-${GH_PROJECT}-${PORTVERSION}-${GH_COMMIT}

MAINTAINER=	fk@fabiankeil.de
COMMENT=	Tor-managed pluggable transport client

LIB_DEPENDS=	liballium-1.0.so:${PORTSDIR}/devel/liballium \
		libevent.so:${PORTSDIR}/devel/libevent2

USE_GITHUB=	yes
GH_ACCOUNT=	Yawning
GH_COMMIT=	3c551c5
GH_TAGNAME=	${GH_COMMIT}

GNU_CONFIGURE=	yes
USES=		compiler:c++11-lib libtool:build pkgconfig tar:bzip2
USE_AUTOTOOLS=	autoconf aclocal automake

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	COPYING

pre-configure:
	@(cd ${WRKSRC} && ./autogen.sh)

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${STAGEDIR}${DOCSDIR}

regression-test: build
	(cd ${WRKSRC} && make check)

.include <bsd.port.mk>
