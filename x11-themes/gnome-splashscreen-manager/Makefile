# New ports collection makefile for:	gnome-splashscreen-manager
# Date created:		2005-04-15
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome-splashscreen-manager
PORTVERSION=	0.2
CATEGORIES=	x11-themes
MASTER_SITES=	http://www.miketech.net/gnome-art/download/
DISTNAME=	gnome-art-${PORTVERSION}

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Gnome splash screen manager

BUILD_DEPENDS=	gnome-session:${PORTSDIR}/x11/gnomesession \
		ruby-glade-create-template:${PORTSDIR}/devel/ruby-libglade2 \
		${RUBY_SITEARCHLIBDIR}/gnome2.so:${PORTSDIR}/x11/ruby-gnome2 \
		${RUBY_SITEARCHLIBDIR}/gconf2.so:${PORTSDIR}/devel/ruby-gconf2
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/gnome-art/${PORTNAME}
USE_RUBY=	yes
USE_REINPLACE=	yes
USE_RUBY_SETUP=	yes
GSPLASH=	${X11BASE}/share/gnome/pixmaps/splash
SPLASH_ICON=	${DATADIR}/glade/gnome-graphics.png

post-patch:
	@${SED} -e 's|%%COMMENT%%|${COMMENT}|; \
		s|%%SPLASH_ICON%%|${SPLASH_ICON}|' \
		< ${FILESDIR}/gnome-splashscreen-manager.desktop.in \
		> ${WRKDIR}/gnome-splashscreen-manager.desktop
	cd ${WRKSRC}/lib/gnome-splashscreen-manager/ && \
	for file in `${FIND} ${GSPLASH} -type f` ; do \
		${SED} -e 's|%%SPLASHSCREENS%%|\\n<splash_screen>\\n\\t<name>%%F%%</name>\\n\\t<filename>%%F%%</filename>\\n\\t<description>...</description>\\n\\t<author>?</author>\\n\\t<license>unknown</license>\\n</splash_screen>\\n%%SPLASHSCREENS%%|' \
		< gnome_splashscreen_manager.rb > gnome_splashscreen_manager.rb.bak ; \
		${SED} -e "s|%%F%%|$${file}|g" < gnome_splashscreen_manager.rb.bak > gnome_splashscreen_manager.rb ; \
	done
	@${REINPLACE_CMD} -e 's|%%SPLASHSCREENS%%||' \
		${WRKSRC}/lib/gnome-splashscreen-manager/gnome_splashscreen_manager.rb
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|' \
		${WRKSRC}/lib/gnome-splashscreen-manager/ui/main_window.rb
	@${FIND} ${WRKSRC} -name '*.bak' -delete

post-install:
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKDIR}/gnome-splashscreen-manager.desktop ${PREFIX}/share/applications

.include <bsd.port.mk>
