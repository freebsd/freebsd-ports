# New ports collection makefile for:	jabber-aim
# Date created:			14 Apr 2002
# Whom:				Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	aim
PORTVERSION=	20040131.b
CATEGORIES=	net
MASTER_SITES=	http://aim-transport.jabberstudio.org/
PKGNAMEPREFIX=	jabber-
PKGNAMESUFFIX=	-transport
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-stable-${PORTVERSION:R}${PORTVERSION:E}
DIST_SUBDIR=	jabber

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	Jabber AIM Transport module

BUILD_DEPENDS=	${LOCALBASE}/sbin/jabberd:${PORTSDIR}/net/jabber

WRKSRC=		${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}-stable-${PORTVERSION:R}
PLIST_FILES=	lib/jabber/aimtrans.so
USE_GMAKE=	yes
USE_AUTOCONF_VER=	259
USE_ICONV=	yes

CONFIGURE_ARGS+=--with-jabberd=${LOCALBASE}/include/jabber
CONFIGURE_ENV=	LDFLAGS="-liconv" LIBS="-L${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include/pth -I${LOCALBASE}/include"

do-install:
	@${MKDIR} ${PREFIX}/lib/jabber
	${INSTALL_DATA} ${WRKSRC}/src/aimtrans.so ${PREFIX}/lib/jabber

post-install:
	@${CAT} pkg-message

.include <bsd.port.mk>
