# Ports collection makefile for:  htdump
# Date created:                   Tue Feb 20, 2001
# Whom:                           Maxime Henrion (mux@qualys.com)
#
# $FreeBSD$
#

PORTNAME=	htdump
PORTVERSION=	0.9x
CATEGORIES=	www
MASTER_SITES=	http://arak.cs.hro.nl/~ren/linux/htdump/bin/

MAINTAINER=	mux@qualys.com

LIB_DEPENDS=    gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

.if defined(WITH_SSL)
USE_OPENSSL=	yes
ALL_TARGET=	ssl
.endif

pre-extract:
.if !defined(WITH_SSL)
	@${ECHO} "Define WITH_SSL if you want to build with SSL support"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/htdump ${PREFIX}/bin

.include <bsd.port.mk>
