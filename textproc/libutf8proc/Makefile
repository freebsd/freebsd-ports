# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	libutf8proc
PORTVERSION=	1.3.1
CATEGORIES=	textproc
MASTER_SITES=	http://download.netsurf-browser.org/libs/releases/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	UTF8 Processing library

LICENSE=	MIT

BUILD_DEPENDS=	netsurf-buildsystem>=1.5:devel/netsurf-buildsystem

USES=	gmake
USE_LDCONFIG=	yes

WRKSRC=	${WRKDIR}/${DISTNAME:S/-src//}

MAKE_ENV+=	COMPONENT_TYPE="lib-shared"

PLIST_SUB+=	VERSION=${PORTVERSION}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libutf8proc.so*

.include <bsd.port.mk>
