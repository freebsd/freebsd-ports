# Ports collection makefile for:  msmtp-devel
# Date created:                   10 Jan 2005
# Whom:                           Roman Bogorodskiy <bogorodskiy@inbox.ru>
#
# $FreeBSD$
#

PORTNAME=	msmtp
PORTVERSION=	1.3.9
CATEGORIES=	mail ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	msmtp
PKGNAMESUFFIX=	-devel

MAINTAINER=	novel@FreeBSD.org
COMMENT=	SMTP plugin for MUAs

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GETOPT_LONG=yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
MAN1=		msmtp.1
INFO=	msmtp
PLIST_FILES=	bin/msmtp

# conflicts with mail/msmtp
CONFLICTS=	msmtp-1.2.*

# XXX we need gnutls >= 1.2.0 which is not avaible via ports tree
.if defined(WITH_GNUTLS)
.undef WITH_GNUTLS
.endif

.if defined(WITH_GNUTLS)
LIB_DEPENDS+=	gnutls.12:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--with-ssl=gnutls
.elif defined (WITH_OPENSSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-ssl=openssl
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

.if defined(WITH_GSASL)
LIB_DEPENDS+=	gsasl.9:${PORTSDIR}/security/gsasl
.else
CONFIGURE_ARGS+=	--disable-gsasl
.endif

.include <bsd.port.mk>
