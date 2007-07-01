# Ports collection makefile for:  msmtp
# Date created:                   22 Aug 2003
# Whom:                           R.I.Pienaar <rip@devco.net>
#
# $FreeBSD$
#

PORTNAME=	msmtp
PORTVERSION=	1.4.12
PORTREVISION=	1
CATEGORIES=	mail ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	msmtp

MAINTAINER=	novel@FreeBSD.org
COMMENT=	SMTP plugin for MUAs

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GETOPT_LONG=yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--infodir="${PREFIX}/info" --mandir="${PREFIX}/man"
MAN1=	msmtp.1
INFO=	msmtp

.if defined(WITH_GNUTLS)
LIB_DEPENDS+=	gnutls.13:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--with-ssl=gnutls
.elif defined(WITH_OPENSSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-ssl=openssl
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

.if defined(WITH_GNUTLS) || defined(WITH_OPENSSL)
RUN_DEPENDS+=	${LOCALBASE}/share/certs/ca-root.crt:${PORTSDIR}/security/ca-roots
.endif

.if defined(WITH_GSASL)
LIB_DEPENDS+=	gsasl.10:${PORTSDIR}/security/gsasl
.else
CONFIGURE_ARGS+=	--without-gsasl
.endif

.if !defined(WITHOUT_IDN)
LIB_DEPENDS+=	idn.16:${PORTSDIR}/dns/libidn
CONFIGURE_ARGS+=	--with-libidn
.else
CONFIGURE_ARGS+=	--without-libidn
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=		yes
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB=		NLS="@comment "
.endif

.include <bsd.port.mk>
