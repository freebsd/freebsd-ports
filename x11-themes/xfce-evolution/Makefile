# $FreeBSD$

PORTNAME=	xfce-evolution
DISTVERSION=	3.1.6
CATEGORIES=	x11-themes
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	fbsd@opal.com
COMMENT=	Complete Xfce Evolution Gtk2, Gtk3, Qt4, Qt5, wxWidgets, Xfce themes

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

RUN_DEPENDS=	gtk-murrine-engine>0:x11-themes/gtk-murrine-engine \
		qt5-style-plugins>0:x11-themes/qt5-style-plugins

USES=		shebangfix zip:infozip # infozip because unzip on 10 doesn't unpack symbolic links
USE_GNOME=	gtk20:build
NO_BUILD=	yes
NO_ARCH=	yes
SHEBANG_REGEX=	00.[0-4]0
bash_CMD=	/bin/sh

EXTRACT_AFTER_ARGS=	-d ${DISTNAME}

post-extract:
	@cd ${WRKSRC} && \
		for d in "Xfce Evolution "*; do \
			${MV} "$$d" $$(${ECHO} $$d | ${SED} 's/ /-/g'); \
		done

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/themes
	@cd ${WRKSRC} && \
		${COPYTREE_SHARE} "Xfce-Evolution-*" ${STAGEDIR}${PREFIX}/share/themes;

.include <bsd.port.mk>
