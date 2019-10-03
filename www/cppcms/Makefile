# $FreeBSD$

PORTNAME=	cppcms
PORTVERSION=	1.2.1
PORTREVISION=	7
CATEGORIES=	www
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ web development framework

LICENSE=	MIT

LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		cmake python:2.7 shebangfix ssl tar:bzip2
USE_LDCONFIG=	yes
SHEBANG_FILES=	bin/cppcms_tmpl_cc

OPTIONS_DEFINE=	EXAMPLES GCRYPT ICU
OPTIONS_DEFAULT=ICU
ICU_DESC=	ICU unicode support

GCRYPT_CMAKE_BOOL=	DISABLE_GCRYPT
GCRYPT_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt
ICU_CMAKE_BOOL=		DISABLE_ICONV
ICU_LIB_DEPENDS=	libicuuc.so:devel/icu
ICU_USE=		CXXSTD=gnu++11
ICU_USES=		compiler:c++11-lib
ICU_USES_OFF=		iconv

post-patch:
	@${REINPLACE_CMD} -e 's|python2|${PYTHON_VERSION}|' ${WRKSRC}/CMakeLists.txt

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
