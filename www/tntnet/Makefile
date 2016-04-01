# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tntnet
PORTVERSION=	2.2.1
PORTREVISION=	5
CATEGORIES=	www devel
MASTER_SITES=	http://www.tntnet.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Webapplicationserver for C++

LIB_DEPENDS=	libcxxtools.so:devel/cxxtools
BUILD_DEPENDS=	zip:archivers/zip

USES=		cpe iconv libtool pathfix pkgconfig shebangfix
SHEBANG_FILES=	tntnet-conf2xml.pl
USE_CSTD=	gnu89
PATCH_STRIP=	-p1
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--localstatedir=/var

.if defined(WITH_GNUTLS)
CONFIGURE_ARGS+=	--with-ssl=gnutls
LIB_DEPENDS+=	libgnutls.so:security/gnutls
.else
CONFIGURE_ARGS+=	--with-ssl=openssl
USE_OPENSSL=	yes
.endif

USERS=		www
GROUPS=		www

post-configure:
	${REINPLACE_CMD} 's/^\(#define[[:space:]]*HAVE_SENDFILE[[:space:]]*\).*/\1\0/' ${WRKSRC}/framework/common/config.h

.include <bsd.port.mk>
