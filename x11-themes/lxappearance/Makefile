# Created by: chinsan
# $FreeBSD$

PORTNAME=	lxappearance
PORTVERSION=	0.5.2
PORTREVISION=	1
CATEGORIES=	x11-themes gnome
MASTER_SITES=	SF/lxde/LXAppearance

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	A desktop-independent theme switcher for GTK+

LICENSE=	GPLv2

USE_GNOME=	gnomehack gtk20 intlhack
USES=		gettext
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		lxappearance.1

.include <bsd.port.pre.mk>

# earlier versions don't have mkdtemp(3) in stdlib.h
.if ${OSVERSION} < 800000
EXTRA_PATCHES+=	${FILESDIR}/extra-src-utils.c
.endif

.include <bsd.port.post.mk>
