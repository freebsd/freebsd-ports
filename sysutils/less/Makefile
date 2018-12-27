# Created by: Andrey A. Chernov <ache@FreeBSD.org>
# $FreeBSD$

PORTNAME=	less
PORTVERSION=	530
CATEGORIES=	sysutils
MASTER_SITES=	http://www.greenwoodsoftware.com/less/ \
		http://bitrote.org/distfiles/

MAINTAINER=	jharris@widomaker.com
COMMENT=	Better pager utility

LICENSE=	GPLv3

USES=		cpe ncurses
CPE_VENDOR=	gnu

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/less bin/lesskey bin/lessecho \
		man/man1/less.1.gz man/man1/lesskey.1.gz \
		man/man1/lessecho.1.gz

OPTIONS_DEFINE=	COLORS
COLORS_DESC=	Enable colors support via escape sequence

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCOLORS}
CPPFLAGS+=	-DCOLOR_LESS

pre-fetch:
	@${ECHO_MSG} "Making a color version of less."
.endif

.include <bsd.port.mk>
