# New ports collection makefile for:	jabber-aim
# Date created:			14 Apr 2002
# Whom:				Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	aim
PORTVERSION=	0.9.24c
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://download.jabber.org/dists/transports/aim-transport/
PKGNAMEPREFIX=	jabber-
PKGNAMESUFFIX=	-transport
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}
DIST_SUBDIR=	jabber

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	Jabber AIM Transport module

BUILD_DEPENDS=	${LOCALBASE}/sbin/jabberd:${PORTSDIR}/net/jabber

PLIST_FILES=	lib/jabber/aimtrans.so
USE_GMAKE=	yes
USE_AUTOCONF_VER=	213

CONFIGURE_ARGS+=--with-jabberd=${LOCALBASE}/include/jabber
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include/pth

do-install:
	@${MKDIR} ${PREFIX}/lib/jabber
	${INSTALL_DATA} ${WRKSRC}/src/aimtrans.so ${PREFIX}/lib/jabber

post-install:
	@${CAT} pkg-message

.include <bsd.port.mk>
