# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	libwapcaplet
PORTVERSION=	0.4.2
CATEGORIES=	textproc
MASTER_SITES=	http://download.netsurf-browser.org/libs/releases/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	String internment library

LICENSE=	MIT

BUILD_DEPENDS=	netsurf-buildsystem>=1.5:devel/netsurf-buildsystem \
		${LOCALBASE}/bin/flex:textproc/flex

USES=		gmake
USE_LDCONFIG=	yes

MAKE_ENV=	COMPONENT_TYPE="lib-shared" \
		FLEX="${LOCALBASE}/bin/flex"

PLIST_SUB=	VERSION=${PORTVERSION}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libwapcaplet.so

.include <bsd.port.mk>
