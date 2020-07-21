# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	libhubbub
PORTVERSION=	0.3.7
CATEGORIES=	www
MASTER_SITES=	http://download.netsurf-browser.org/libs/releases/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTML5 parser library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	netsurf-buildsystem>=1.5:devel/netsurf-buildsystem
LIB_DEPENDS=	libparserutils.so:devel/libparserutils

USES=		gmake iconv:wchar_t localbase pkgconfig
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}

MAKE_ENV+=	COMPONENT_TYPE="lib-shared"
LDFLAGS+=	${ICONV_LIB}

PLIST_SUB+=	VERSION=${PORTVERSION}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libhubbub.so*

.include <bsd.port.mk>
