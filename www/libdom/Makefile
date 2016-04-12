# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	libdom
PORTVERSION=	0.3.0
CATEGORIES=	www
MASTER_SITES=	http://download.netsurf-browser.org/libs/releases/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Document Object Model library

LICENSE=	MIT

BUILD_DEPENDS=	netsurf-buildsystem>=1.5:devel/netsurf-buildsystem
LIB_DEPENDS=	libwapcaplet.so:textproc/libwapcaplet \
	libparserutils.so:devel/libparserutils \
	libhubbub.so:www/libhubbub \
	libexpat.so:textproc/expat2

USES=	gmake localbase pkgconfig
USE_LDCONFIG=	yes

WRKSRC=	${WRKDIR}/${DISTNAME:S/-src//}

MAKE_ENV+=	COMPONENT_TYPE="lib-shared"

PLIST_SUB+=	VERSION=${PORTVERSION}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libdom.so*

.include <bsd.port.mk>
