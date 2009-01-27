# Ports collection makefile for: sipxmedialib
# Date created: Jan 8, 2007
# Whom: Michael Durian <durian@shadetreesoftware.com>
#
# $FreeBSD$
#

PORTNAME=	sipxmedialib
PORTVERSION=	3.6.0
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://www.sipfoundry.org/pub/sipX/3.6/SRC/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	sipX library for media streams

BUILD_DEPENDS=	ginstall:${PORTSDIR}/sysutils/coreutils \
		cppunit-config:${PORTSDIR}/devel/cppunit
LIB_DEPENDS=	sipXport:${PORTSDIR}/net/sipxportlib \
		sipXtack:${PORTSDIR}/net/sipxtacklib \
		pcre.0:${PORTSDIR}/devel/pcre

DEPRECATED=		old version, needs updating
EXPIRATION_DATE=	2009-03-27

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:262:env automake:19:env
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
LOCALSTATEDIR=	/var
CONFIGURE_ENV+=	wwwdir=${PREFIX}/www/sipX \
		INSTALL=`which ginstall`
CONFIGURE_ARGS+=	--enable-sip-tls \
		--prefix=${PREFIX} \
		--localstatedir=${LOCALSTATEDIR}

.include <bsd.port.mk>
