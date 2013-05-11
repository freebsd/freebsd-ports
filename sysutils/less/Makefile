# Created by: ache
# $FreeBSD$

PORTNAME=	less
PORTVERSION=	458
CATEGORIES=	sysutils
MASTER_SITES=	http://www.greenwoodsoftware.com/%SUBDIR%/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	less

MAINTAINER=	jharris@widomaker.com
COMMENT=	A better pager utility

LICENSE=	GPLv3

OPTIONS_DEFINE=	COLOR_LESS
COLOR_LESS_DESC=Enables color support via escape sequence

PLIST_FILES=	bin/less bin/lesskey bin/lessecho

.include <bsd.port.options.mk>

GNU_CONFIGURE=	yes
MAN1=		less.1 lesskey.1 lessecho.1

.if ${PORT_OPTIONS:MCOLOUR_LESS}
CPPFLAGS+=	-DCOLOR_LESS

pre-fetch:
	@${ECHO_MSG} "Making a color version of less."
.endif

.include <bsd.port.mk>
