# ex:ts=8
# Ports collection makefile for:	serveez
# Date created:			May 16, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	serveez
PORTVERSION=	0.1.5
PORTREVISION=	1
CATEGORIES=	net devel
MASTER_SITES=	ftp://gatekeeper.dec.com/pub/GNU/serveez/ \
		http://www.textsure.net/~ela/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A server framework

LIB_DEPENDS=	guile.15:${PORTSDIR}/lang/guile
.if !exists(/usr/bin/bzip2)
LIB_DEPENDS+=	bz2.1:${PORTSDIR}/archivers/bzip2
.endif

GUILE_CONFIG?=	${LOCALBASE}/bin/guile-config

USE_GETOPT_LONG=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes

MAN1=	serveez.1 serveez-config.1
INFO=	serveez serveez-api

CPPFLAGS=	`${GUILE_CONFIG} compile`
LDFLAGS=	`${GUILE_CONFIG} link`

post-patch:
	@${REINPLACE_CMD} -e 's|-release||g' \
		${WRKSRC}/src/libserveez/Makefile.in

.include <bsd.port.mk>
