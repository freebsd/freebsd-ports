# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	libdom
PORTVERSION=	0.3.3
DISTVERSIONSUFFIX=	-src
CATEGORIES=	www
MASTER_SITES=	http://download.netsurf-browser.org/libs/releases/

MAINTAINER=	neel@neelc.org
COMMENT=	Document Object Model library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	netsurf-buildsystem>=1.5:devel/netsurf-buildsystem
LIB_DEPENDS=	libwapcaplet.so:textproc/libwapcaplet \
		libparserutils.so:devel/libparserutils \
		libhubbub.so:www/libhubbub \
		libexpat.so:textproc/expat2

USES=		gmake iconv localbase pkgconfig
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAKE_ENV=	COMPONENT_TYPE="lib-shared"

PLIST_SUB=	VERSION=${PORTVERSION}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libdom.so

.include <bsd.port.mk>
