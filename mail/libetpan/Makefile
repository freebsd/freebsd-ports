# ex:ts=8
# Ports collection makefile for:	libEtPan!
# Date created:			Jun 27, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libetpan
PORTVERSION=	0.58
CATEGORIES=	mail ipv6
MASTER_SITES=	SF

MAINTAINER=	c0rn@o2.pl
COMMENT=	A mail library

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		expat:${PORTSDIR}/textproc/expat2 \
		sasl2.2:${PORTSDIR}/security/cyrus-sasl2

USE_ICONV=	yes
USE_AUTOTOOLS=	libtool:22 autoconf:262
USE_LDCONFIG=	yes
USE_GMAKE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

OPTIONS=	GNUTLS	"Enable gnuTLS support" off \
		IPV6	"Enable ipv6 support." on

.if defined(WITH_GNUTLS)
LIB_DEPENDS+=	gnutls.26:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--without-openssl --with-gnutls
.else
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--without-gnutls
.endif

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.else
CONFIGURE_ARGS+=	--enable-ipv6
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|2.61|2.62|g' ${WRKSRC}/aclocal.m4

.include <bsd.port.mk>
