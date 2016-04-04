# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	libcss
PORTVERSION=	0.6.0
CATEGORIES=	textproc
MASTER_SITES=	http://download.netsurf-browser.org/libs/releases/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Cascading Style Sheets library

LICENSE=	MIT

BUILD_DEPENDS=	netsurf-buildsystem>=1.5:devel/netsurf-buildsystem
LIB_DEPENDS=	libwapcaplet.so:textproc/libwapcaplet \
	libparserutils.so:devel/libparserutils

USES=	gmake iconv:wchar_t localbase pkgconfig
USE_LDCONFIG=	yes

WRKSRC=	${WRKDIR}/${DISTNAME:S/-src//}

MAKE_ENV+=	COMPONENT_TYPE="lib-shared"
LDFLAGS+=	${ICONV_LIB}

PLIST_SUB+=	VERSION=${PORTVERSION}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcss.so*

.include <bsd.port.mk>
