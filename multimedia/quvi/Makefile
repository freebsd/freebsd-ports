# New ports collection makefile for:	quvi
# Date created:		2 February 2010
# Whom:			Toni Gundogdu <legatvs@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	quvi
PORTVERSION=	0.2.6
CATEGORIES=	multimedia devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Query video library for Youtube like websites

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		pcre.0:${PORTSDIR}/devel/pcre

LICENSE=	GPLv3

CONFIGURE_ARGS=	--enable-broken --enable-examples
CONFIGURE_ENV=	CPPFLAGS='${CPPFLAGS} -I${WRKSRC}/include \
		-I${LOCALBASE}/include'
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack pkgconfig
USE_ICONV=	yes
USE_LDCONFIG=	yes
USE_LUA=	yes

MAN1=		quvi.1
PLIST_SUB=	SHLIB_VER="${SHLIB_VER}"

OPTIONS=	SMUT "Enable adult website support" off

SHLIB_VER=	2

.if defined(NOPORTDOCS)
CONFIGURE_ARGS+=--without-doc
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_SMUT)
CONFIGURE_ARGS+=--enable-smut
PLIST_SUB+=	SMUT=""
.else
PLIST_SUB+=	SMUT="@comment "
.endif

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/install-data-am:/ s| install-docDATA||' \
		${WRKSRC}/doc/Makefile.in
.endif

.include <bsd.port.post.mk>
