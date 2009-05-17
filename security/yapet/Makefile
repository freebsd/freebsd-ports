# New ports collection makefile for:	yapet
# Date created:		01 March 2008
# Whom:			Rafael Ostertag <rafi@guengel.ch>
#
# $FreeBSD$
#

PORTNAME=	yapet
PORTVERSION=	0.3
CATEGORIES=	security
MASTER_SITES=	http://www.guengel.ch/myapps/yapet/downloads/ http://homepage.hispeed.ch/rostertag/yapet/

MAINTAINER=	rafi@guengel.ch
COMMENT=	A curses based password manager

MAN1=		yapet.1
MANCOMPRESSED=	no

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes

OPTIONS=		TTITLE "Enable Terminal Title" ON

.include <bsd.port.pre.mk>

.if defined(WITH_TTITLE)
CONFIGURE_ARGS+=	--enable-terminal-title
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=		yes
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib
PLIST_SUB+=		NLS=""
CONFIGURE_ENV=		CPPFLAGS="${CPPFLAGS}" \
			LDFLAGS="${LDFLAGS}"
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

.include <bsd.port.post.mk>
