# New ports collection makefile for:   lxappearance
# Date created:                2008/06/20
# Whom:                        chinsan
#
# $FreeBSD$
#

PORTNAME=	lxappearance
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	x11-themes gnome
MASTER_SITES=	SF/lxde/LXAppearance

MAINTAINER=	c0rn@o2.pl
COMMENT=	A desktop-independent theme switcher for GTK+

LICENSE=	GPLv2

USE_GNOME=	gnomehack gtk20 intlhack
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.pre.mk>

# earlier versions don't have mkdtemp(3) in stdlib.h
.if ${OSVERSION} < 800000
EXTRA_PATCHES+=	${FILESDIR}/extra-src-utils.c
.endif

.include <bsd.port.post.mk>
