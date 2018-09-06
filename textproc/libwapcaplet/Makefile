# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	libwapcaplet
PORTVERSION=	0.4.1
DISTVERSIONSUFFIX=	-src
CATEGORIES=	textproc
MASTER_SITES=	http://download.netsurf-browser.org/libs/releases/

MAINTAINER=	neel@neelc.org
COMMENT=	String internment library

LICENSE=	MIT

BUILD_DEPENDS=	netsurf-buildsystem>=1.5:devel/netsurf-buildsystem \
	${LOCALBASE}/bin/flex:textproc/flex

USES=	gmake
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAKE_ENV=	COMPONENT_TYPE="lib-shared" \
		FLEX="${LOCALBASE}/bin/flex"

PLIST_SUB=	VERSION=${PORTVERSION}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libwapcaplet.so

.include <bsd.port.mk>
