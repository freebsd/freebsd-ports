# New ports collection makefile for:	Jabber MSN Transport
# Date created:				Sat May 04 06:00:02 PDT 2002
# Whom:					Martijn Lina <martijn@pacno.net>
#
# $FreeBSD$

PORTNAME=	msn-transport
PORTVERSION=	1.2.1
CATEGORIES=	net
MASTER_SITES=	http://msn-transport.jabberstudio.org/
PKGNAMEPREFIX=	jabber-

MAINTAINER=	martijn@pacno.net
COMMENT=	Jabber MSN-Transport module

BROKEN=		"Does not build"

BUILD_DEPENDS=	${LOCALBASE}/sbin/jabberd:${PORTSDIR}/net/jabber

USE_GMAKE=	yes
USE_AUTOHEADER=	yes
USE_AUTOMAKE=	yes
AUTOMAKE_ARGS+=	--include-deps --add-missing --foreign
USE_AUTOMAKE_VER=	14
CONFIGURE_ARGS+=	--with-jabberd=${PREFIX}/include/jabber

pre-configure:
	@cd ${WRKSRC} ; \
	aclocal14 && autoheader

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/msntrans.so ${PREFIX}/lib/jabber/

.include <bsd.port.mk>
