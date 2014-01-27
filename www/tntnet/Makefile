# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tntnet
PORTVERSION=	2.2.1
CATEGORIES=	www devel
MASTER_SITES=	http://www.tntnet.org/download/

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Webapplicationserver for C++

LIB_DEPENDS=	libcxxtools.so:${PORTSDIR}/devel/cxxtools
BUILD_DEPENDS+=	zip:${PORTSDIR}/archivers/zip

USES=		iconv pkgconfig pathfix
USE_CSTD=	gnu89
PATCH_STRIP=	-p1
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -pthread
CONFIGURE_ARGS+=	--localstatedir=/var

.if defined(WITH_GNUTLS)
LDFLAGS+=	-lgnutls
CONFIGURE_ARGS+=	--with-ssl=gnutls
LIB_DEPENDS+=	gnutls:${PORTSDIR}/security/gnutls
.else
CONFIGURE_ARGS+=	--with-ssl=openssl
.endif

USERS=		www
GROUPS=		www

post-configure:
	${REINPLACE_CMD} 's/^\(#define[[:space:]]*HAVE_SENDFILE[[:space:]]*\).*/\1\0/' ${WRKSRC}/framework/common/config.h

.include <bsd.port.mk>
