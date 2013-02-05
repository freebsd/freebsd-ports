# ex:ts=8
# Ports collection makefile for:	libEtPan!
# Date created:			Jun 27, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libetpan
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	mail ipv6
MASTER_SITES=	SF

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	A mail library

LICENSE=	BSD

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		expat:${PORTSDIR}/textproc/expat2 \
		sasl2:${PORTSDIR}/security/cyrus-sasl2

USE_ICONV=	yes
USE_AUTOTOOLS=	libtool autoconf
USE_LDCONFIG=	yes
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

OPTIONS_DEFINE=		IPV6
OPTIONS_SINGLE=		CRYPTO
OPTIONS_SINGLE_CRYPTO=	GNUTLS OPENSSL 
GNUTLS_DESC=		Enable GNUTLS support
OPENSSL_DESC=		Enable OpenSSL support
OPTIONS_DEFAULT=	IPV6 OPENSSL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	gnutls.26:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--without-openssl --with-gnutls
.endif

.if ${PORT_OPTIONS:MOPENSSL}
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--without-gnutls
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

AUTOTOOLSFILES=	aclocal.m4

post-patch:
	@${REINPLACE_CMD} -e 's|2.61|%%AUTOCONF_VERSION%%|g' ${WRKSRC}/aclocal.m4

.include <bsd.port.mk>
