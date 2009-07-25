# New ports collection makefile for:	yapet
# Date created:		01 March 2008
# Whom:			Rafael Ostertag <rafi@guengel.ch>
#
# $FreeBSD$
#

PORTNAME=	yapet
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.guengel.ch/myapps/yapet/downloads/ http://homepage.hispeed.ch/rostertag/yapet/

PATCH_SITES=	http://www.guengel.ch/myapps/yapet/downloads/patches/ http://homepage.hispeed.ch/rostertag/yapet/patches/
PATCHFILES=	yapet_cfgfile-0.4.diff yapet_csv2yapet-0.4.diff
PATCH_DIST_STRIP=	-p1

MAINTAINER=	rafi@guengel.ch
COMMENT=	A curses based password manager

MAN1=		yapet.1
MANCOMPRESSED=	no

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:262 automake:110 aclocal:110
ACLOCAL_ARGS=	-I m4

OPTIONS=	TTITLE "Enable Terminal Title" ON \
		CSV2YAPET "Build csv2yapet" ON

.include <bsd.port.pre.mk>

.if defined(WITH_TTITLE)
CONFIGURE_ARGS+=	--enable-terminal-title
.else
CONFIGURE_ARGS+=	--disable-terminal-title
.endif

.if defined(WITH_CSV2YAPET)
CONFIGURE_ARGS+=	--enable-csv2yapet
MAN1+=			csv2yapet.1
PLIST_SUB+=		CSV2YAPET=""
.else
CONFIGURE_ARGS+=	--disable-csv2yapet
PLIST_SUB+=		CSV2YAPET="@comment "
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

.if !defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--enable-install-doc
PLIST_SUB+=		NOPORTDOCS=""
.else
CONFIGURE_ARGS+=	--disable-install-doc
PLIST_SUB+=		NOPORTDOCS="@comment "
.undef MAN1
.undef MANCOMPRESSED
.endif

.include <bsd.port.post.mk>
