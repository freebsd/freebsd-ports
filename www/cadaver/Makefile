# New ports collection makefile for: cadaver
# Date created:		13 January 2000
# Whom:			Alex Povolotsky <tarkhil@over.ru>
#
# $FreeBSD$
#

PORTNAME=	cadaver
PORTVERSION=	0.22.2
CATEGORIES=	www
MASTER_SITES=	http://www.webdav.org/cadaver/ \
		http://www.tcbug.org/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.asc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	josh@tcbug.org
COMMENT=	Commandline client for DAV

LIB_DEPENDS=	neon:${PORTSDIR}/www/neon

USE_GPG?=	yes
SIG_FILES=	${DISTNAME}${EXTRACT_SUFX}.asc
USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-netrc
ALL_TARGET=	cadaver

MAN1=		cadaver.1
PLIST_FILES=	bin/cadaver
# Neither expat nor libneon are needed at all, but the configure
# script breaks if it can not find the Makefile* in them. Exclude
# them to be sure, a stray .h is not included instead of what's
# found under PREFIX (installed by the neon port):
EXTRACT_AFTER_ARGS=	| ${TAR} -xf - \
		--exclude '${PORTNAME}-${PORTVERSION}/expat/*.[ch]' \
		--exclude '${PORTNAME}-${PORTVERSION}/libneon/*.[ch]'

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.if !defined(WITHOUT_OPENSSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-ssl --with-force-ssl
.endif

.include <bsd.port.mk>
