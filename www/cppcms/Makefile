# $FreeBSD$

PORTNAME=	cppcms
PORTVERSION=	1.2.0
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	SF/cppcms/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ web development framework

LICENSE=	LGPL3

LIB_DEPENDS=	libpcre.so:devel/pcre

BROKEN_powerpc64=	Does not build: error: 'localeconv_l' was not declared in this scope

USES=		cmake python:2.7 shebangfix tar:bzip2 ssl
USE_LDCONFIG=	yes
SHEBANG_FILES=	bin/cppcms_tmpl_cc

OPTIONS_DEFINE=		EXAMPLES GCRYPT ICU
OPTIONS_DEFAULT=	ICU
ICU_DESC=		ICU unicode support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MICU}
USES+=		compiler:c++11-lib
USE_CXXSTD=	gnu++11
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

post-patch:
	${REINPLACE_CMD}  -e 's/python2/${PYTHON_VERSION}/' ${WRKSRC}/CMakeLists.txt

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
