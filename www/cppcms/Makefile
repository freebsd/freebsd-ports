# $FreeBSD$

PORTNAME=	cppcms
PORTVERSION=	1.0.5
CATEGORIES=	www
MASTER_SITES=	SF/cppcms/${PORTNAME}/${PORTVERSION}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	C++ web development framework

LICENSE=	LGPL3

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

USES=		cmake tar:bzip2
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		EXAMPLES GCRYPT ICU
OPTIONS_DEFAULT=	ICU
GCRYPT_DESC=		libgcrypt support
ICU_DESC=		ICU unicode support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MICU}
LIB_DEPENDS+=	libicuuc.so:${PORTSDIR}/devel/icu
CMAKE_ARGS+=	-DDISABLE_ICONV:BOOL=ON
.else
USES+=		iconv
CMAKE_ARGS+=	-DDISABLE_ICU_LOCALE:BOOL=ON
.endif

.if ${PORT_OPTIONS:MGCRYPT}
LIB_DEPENDS+=	libgcrypt.so:${PORTSDIR}/security/libgcrypt
CMAKE_ARGS+=	-DDISABLE_OPENSSL:BOOL=ON
.else
USE_OPENSSL=	yes
CMAKE_ARGS+=	-DDISABLE_GCRYPT:BOOL=ON
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
