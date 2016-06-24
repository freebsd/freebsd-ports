# $FreeBSD$

PORTNAME=	iipsrv
PORTVERSION=	1.0
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	net

MAINTAINER=	me@skylord.ru
COMMENT=	IIP (Internet Imaging Protocol) FastCGI server

LICENSE=	GPLv3

LIB_DEPENDS=	libtiff.so:graphics/tiff

USE_GITHUB=	yes
GH_ACCOUNT=	ruven

USES=		autoreconf jpeg libtool

GNU_CONFIGURE=	yes

USE_RC_SUBR=	${PORTNAME}

PLIST_FILES=	bin/iipsrv.fcgi \
		man/man8/iipsrv.8.gz

post-patch:
	@${REINPLACE_CMD} -e 's|noinst_PROGRAMS|bin_PROGRAMS|g' \
		${WRKSRC}/src/Makefile.am
	@${REINPLACE_CMD} -e 's|include_HEADERS|noinst_HEADERS|g' \
		${WRKSRC}/fcgi/Makefile.am
	@${REINPLACE_CMD} -e 's|include_HEADERS|noinst_HEADERS|g' \
		${WRKSRC}/fcgi/include/Makefile.am

pre-configure:
	@(cd ${WRKSRC} && ./autogen.sh)

.include <bsd.port.mk>
