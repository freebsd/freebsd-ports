# Created by: Andrey A. Chernov <ache@FreeBSD.org>
# $FreeBSD$

PORTNAME=	less
PORTVERSION=	530
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.greenwoodsoftware.com/less/ \
		http://bitrote.org/distfiles/

MAINTAINER=	jharris@widomaker.com
COMMENT=	Better pager utility

LICENSE=	GPLv3

USES=		cpe ncurses

CPE_VENDOR=	gnu
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/less \
		bin/lessecho \
		bin/lesskey \
		man/man1/less.1.gz \
		man/man1/lessecho.1.gz \
		man/man1/lesskey.1.gz

OPTIONS_DEFINE=		COLORS PCRE
OPTIONS_DEFAULT=	COLORS PCRE

PCRE_USES=		localbase
PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre

COLORS_DESC=	Enable colors support via escape sequence

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCOLORS}
CPPFLAGS+=	-DCOLOR_LESS
.endif

.if ${PORT_OPTIONS:MPCRE}
CONFIGURE_ARGS+=	--with-regex=pcre
LDFLAGS+=		-L${LOCALBASE}/lib -lpcre
.else
CONFIGURE_ARGS+=	--with-regex=posix
.endif

.include <bsd.port.mk>
