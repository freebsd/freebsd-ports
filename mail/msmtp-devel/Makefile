# Ports collection makefile for:  msmtp-devel
# Date created:                   2 June 2004
# Whom:                           Roman Bogorodskiy
#
# $FreeBSD$
#

PORTNAME=	msmtp
PORTVERSION=	1.1.1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	msmtp
PKGNAMESUFFIX=	-devel

MAINTAINER=	bogorodskiy@inbox.ru
COMMENT=	The development version of SMTP plugin for MUAs

GNU_CONFIGURE=	yes
USE_GETOPT_LONG=yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
MAN1=		msmtp.1
PLIST_FILES=	bin/msmtp

CONFLICTS=	msmtp-0.* \
		msmtp-1.0.*

.if !defined(WITH_OPENSSL)
WITH_GNUTLS=	yes
.endif

.if defined(WITH_GNUTLS)
LIB_DEPENDS+=	gnutls:${PORTSDIR}/security/gnutls
.endif

.if defined(WITH_OPENSSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-ssl=openssl
.endif

.if defined(WITH_GNU_SASL)
LIB_DEPENDS+=	gsasl:${PORTSDIR}/security/gsasl
.else
CONFIGURE_ARGS+=	--disable-gsasl
.endif

.include <bsd.port.mk>
