# ex:ts=8
# Ports collection makefile for:	serveez
# Date created:			May 16, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	serveez
PORTVERSION=	0.1.5
PORTREVISION=	6
CATEGORIES=	net devel
MASTER_SITES=	ftp://gatekeeper.dec.com/pub/GNU/serveez/ \
		http://www.textsure.net/~ela/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A server framework

LIB_DEPENDS=	guile.20:${PORTSDIR}/lang/guile

GUILE_CONFIG?=	${LOCALBASE}/bin/guile-config

USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes

MAN1=	serveez.1 serveez-config.1
INFO=	serveez serveez-api

CPPFLAGS=	`${GUILE_CONFIG} compile`
LDFLAGS=	`${GUILE_CONFIG} link`

post-patch:
	@${REINPLACE_CMD} -e 's|-release||g' \
		${WRKSRC}/src/libserveez/Makefile.in

.include <bsd.port.mk>
