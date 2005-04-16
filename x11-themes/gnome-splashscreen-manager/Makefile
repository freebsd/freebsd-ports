# New ports collection makefile for:	gnome-splashscreen-manager
# Date created:		2005-04-15
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome-splashscreen-manager
PORTVERSION=	0.1
CATEGORIES=	x11-themes
MASTER_SITES=	http://www.miketech.net/gnome-art/download/
DISTNAME=	gnome-art-${PORTVERSION}

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Gnome splash screen manager

BUILD_DEPENDS=	ruby-glade-create-template:${PORTSDIR}/devel/ruby-libglade2 \
		${RUBY_SITEARCHLIBDIR}/gnome2.so:${PORTSDIR}/x11/ruby-gnome2 \
		${RUBY_SITEARCHLIBDIR}/gconf2.so:${PORTSDIR}/devel/ruby-gconf2
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/gnome-art/${PORTNAME}
USE_RUBY=	yes
USE_REINPLACE=	yes
USE_RUBY_SETUP=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|' \
		${WRKSRC}/lib/gnome-splashscreen-manager/ui/main_window.rb
	@${FIND} ${WRKSRC} -name '*.bak' -delete

.include <bsd.port.mk>
