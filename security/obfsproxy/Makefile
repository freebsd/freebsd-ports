# ports collection makefile for:	obfsproxy
# Date created:				20120220
# Whom:					Carlo Strub
#
# $FreeBSD$
#

PORTNAME=	obfsproxy
DISTVERSION=	20120216
CATEGORIES=	security net
MASTER_SITES=	https://www.c-s.li/ports/

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Tool to obfuscate Tor traffic

LICENSE=	BSD

BUILD_DEPENDS=	tor:${PORTSDIR}/security/tor-devel
RUN_DEPENDS=	tor:${PORTSDIR}/security/tor-devel
LIB_DEPENDS=	event-2.0:${PORTSDIR}/devel/libevent2

USE_AUTOTOOLS=	aclocal autoconf autoheader automake
USE_OPENSSL=	yes
WITH_OPENSSL_PORT=	yes

ACLOCAL_ARGS=	-I m4
AUTOCONF_ARGS=	--include=m4
AUTOHEADER_ARGS=	--include=m4
AUTOMAKE_ARGS=	--add-missing --copy --force-missing
MAN1=		obfsproxy.1
SUB_FILES=	pkg-message
PLIST_FILES=	bin/obfsproxy
USE_GNOME=	pkgconfig

MAKE_JOBS_SAFE=	yes

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
