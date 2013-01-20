# Created by: ache
# $FreeBSD$

PORTNAME=	less
PORTVERSION=	451
CATEGORIES=	sysutils
MASTER_SITES=	http://www.greenwoodsoftware.com/%SUBDIR%/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	less

MAINTAINER=	jharris@widomaker.com
COMMENT=	A better pager utility

PLIST_FILES=	bin/less bin/lesskey bin/lessecho

.include <bsd.port.pre.mk>

GNU_CONFIGURE=	yes
MAN1=		less.1 lesskey.1 lessecho.1

.if defined(COLOUR_LESS) || defined(COLOR_LESS)
CPPFLAGS+=	-DCOLOR_LESS

pre-fetch:
	@${ECHO_MSG} "Making a color version of less."
.endif

.include <bsd.port.post.mk>
