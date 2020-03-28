# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	libcss
PORTVERSION=	0.9.0
CATEGORIES=	textproc
MASTER_SITES=	https://download.netsurf-browser.org/libs/releases/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cascading Style Sheets library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	netsurf-buildsystem>=1.5:devel/netsurf-buildsystem
LIB_DEPENDS=	libwapcaplet.so:textproc/libwapcaplet \
		libparserutils.so:devel/libparserutils

USES=		gmake iconv:wchar_t localbase pkgconfig

USE_LDCONFIG=	yes
MAKE_ENV=	COMPONENT_TYPE="lib-shared"
LDFLAGS+=	${ICONV_LIB}
PLIST_SUB=	VERSION=${PORTVERSION}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcss.so

.include <bsd.port.mk>
