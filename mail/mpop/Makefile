# New ports collection makefile for:    mpop
# Date created:         2009-10-24
# Whom:                 Sylvio Cesar <sylvio@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mpop
PORTVERSION=	1.0.19
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	MPOP is a small and fast POP3 client

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
MAN1=	mpop.1
INFO=	mpop

.if defined(WITH_GNUTLS)
LIB_DEPENDS+=		gnutls.40:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--with-ssl=gnutls
.elif defined(WITH_OPENSSL)
USE_OPENSSL=		yes
CONFIGURE_ARGS+=	--with-ssl=openssl
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

.if defined(WITH_GNUTLS) || defined(WITH_OPENSSL)
RUN_DEPENDS+=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss
.endif

.if defined(WITH_GSASL)
LIB_DEPENDS+=		gsasl.14:${PORTSDIR}/security/gsasl
.else
CONFIGURE_ARGS+=	--without-gsasl
.endif

.if !defined(WITHOUT_IDN)
LIB_DEPENDS+=		idn.16:${PORTSDIR}/dns/libidn
CONFIGURE_ARGS+=	--with-libidn
.else
CONFIGURE_ARGS+=	--without-libidn
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=		yes
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB=		NLS=""
.else
CONFIGURE_ARGS+=	 --disable-nls
PLIST_SUB=		NLS="@comment "
.endif

.include <bsd.port.mk>
