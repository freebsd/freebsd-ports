# New ports collection makefile for:	gnome-art
# Date created:		2005-04-15
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome-art
PORTVERSION=	0.1
CATEGORIES=	x11-themes
MASTER_SITES=	http://www.miketech.net/gnome-art/download/

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Frontend for art.gnome.org

BUILD_DEPENDS=	ruby-glade-create-template:${PORTSDIR}/devel/ruby-libglade2 \
		${RUBY_SITEARCHLIBDIR}/gnome2.so:${PORTSDIR}/x11/ruby-gnome2
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}/${PORTNAME}
USE_RUBY=	yes
USE_REINPLACE=	yes
USE_RUBY_SETUP=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|' \
		${WRKSRC}/lib/gnome-art/ui/main_window.rb \
		${WRKSRC}/lib/gnome-art/ui/download_dialog.rb
	@${FIND} ${WRKSRC} -name '*.bak' -delete

.include <bsd.port.mk>
