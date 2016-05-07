# $FreeBSD$

PORTNAME=	cppcms
PORTVERSION=	1.0.5
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	SF/cppcms/${PORTNAME}/${PORTVERSION}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	C++ web development framework

LICENSE=	LGPL3

BROKEN_powerpc64=	Does not build

BROKEN_FreeBSD_9=	does not build on 9.x

LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		cmake python:2 tar:bzip2
USE_OPENSSL=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		EXAMPLES GCRYPT ICU
OPTIONS_DEFAULT=	ICU
ICU_DESC=		ICU unicode support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MICU}
LIB_DEPENDS+=	libicuuc.so:devel/icu
CMAKE_ARGS+=	-DDISABLE_ICONV:BOOL=ON
.else
USES+=		iconv
CMAKE_ARGS+=	-DDISABLE_ICU_LOCALE:BOOL=ON
.endif

.if ${PORT_OPTIONS:MGCRYPT}
LIB_DEPENDS+=	libgcrypt.so:security/libgcrypt
CMAKE_ARGS+=	-DDISABLE_GCRYPT:BOOL=OFF
.else
CMAKE_ARGS+=	-DDISABLE_GCRYPT:BOOL=ON
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
