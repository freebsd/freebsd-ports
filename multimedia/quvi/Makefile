# New ports collection makefile for:	quvi
# Date created:		2 February 2010
# Whom:			Toni Gundogdu <legatvs@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	quvi
PORTVERSION=	0.2.14
CATEGORIES=	multimedia devel
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION:R}/ \
		GOOGLE_CODE

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Query video library for Youtube like websites

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl

OPTIONS=	NSFW "Enable adult website support" off

LICENSE=	GPLv3

CONFIGURE_ARGS=	--enable-broken --enable-examples
CONFIGURE_ENV=	CPPFLAGS='${CPPFLAGS}'
CPPFLAGS+=	-I${WRKSRC}/include -I${LOCALBASE}/include
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack pkgconfig
USE_ICONV=	yes
USE_LDCONFIG=	yes
USE_LUA=	yes
USE_XZ=		yes

MAN1=		quvi.1

.if defined(NOPORTDOCS)
CONFIGURE_ARGS+=--without-doc
.endif

.include <bsd.port.options.mk>

.if defined(WITH_NSFW)
CONFIGURE_ARGS+=--enable-nsfw
PLIST_SUB+=	NSFW=""
.else
PLIST_SUB+=	NSFW="@comment "
.endif

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/install-data-am:/ s| install-docDATA||' \
		${WRKSRC}/doc/Makefile.in
.endif

.include <bsd.port.mk>
