# New ports collection makefile for:	jabber-aim
# Date created:			14 Apr 2002
# Whom:				Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	aim-transport
PORTVERSION=	0.9.24c
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://download.jabber.org/dists/transports/aim-transport/
PKGNAMEPREFIX=	jabber-
DIST_SUBDIR=	jabber

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	Jabber AIM Transport module

BUILD_DEPENDS=	${LOCALBASE}/sbin/jabberd:${PORTSDIR}/net/jabber

USE_GMAKE=	yes
USE_AUTOCONF=	yes

CONFIGURE_ARGS+=	--with-jabberd=${PREFIX}/include/jabber

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/aimtrans.so ${PREFIX}/lib/jabber/

post-install:
	@cat pkg-message

.include <bsd.port.mk>
