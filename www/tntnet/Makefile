PORTNAME=	tntnet
PORTVERSION=	2.2.1
PORTREVISION=	6
CATEGORIES=	www devel
MASTER_SITES=	http://www.tntnet.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Webapplicationserver for C++
WWW=		https://www.tntnet.org/index.html

BUILD_DEPENDS=	zip:archivers/zip
LIB_DEPENDS=	libcxxtools.so:devel/cxxtools

USES=		cpe iconv libtool localbase:ldflags pathfix pkgconfig \
		shebangfix
USE_CXXSTD=	c++14

SHEBANG_FILES=	tntnet-conf2xml.pl
#USE_CSTD=	gnu89

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--localstatedir=/var

PATCH_STRIP=	-p1

.if defined(WITH_GNUTLS)
CONFIGURE_ARGS+=	--with-ssl=gnutls
LIB_DEPENDS+=	libgnutls.so:security/gnutls
.else
CONFIGURE_ARGS+=	--with-ssl=openssl
USES+=	ssl
.endif

USERS=		www
GROUPS=		www

post-configure:
	${REINPLACE_CMD} 's/^\(#define[[:space:]]*HAVE_SENDFILE[[:space:]]*\).*/\1\0/' ${WRKSRC}/framework/common/config.h

.include <bsd.port.mk>
