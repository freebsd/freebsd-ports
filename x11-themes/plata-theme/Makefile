# $FreeBSD$

PORTNAME=	plata-theme
PORTVERSION=	0.7.9
CATEGORIES=	x11-themes

MAINTAINER=	tagattie@yandex.com
COMMENT=	Gtk theme based on Material Design Refresh

LICENSE=	GPLv2 CC-BY-SA-4.0
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_CC-BY-SA-4.0=	${WRKSRC}/LICENSE_CC_BY_SA4

BUILD_DEPENDS=	inkscape:graphics/inkscape \
		sassc:textproc/sassc \
		bash:shells/bash
RUN_DEPENDS=	gtk-murrine-engine>0:x11-themes/gtk-murrine-engine \
		roboto-fonts-ttf>0:x11-fonts/roboto-fonts-ttf

USES=		autoreconf gmake gnome pkgconfig shebangfix

USE_GITLAB=	yes
GL_SITE=	https://gitlab.com
GL_ACCOUNT=	tista500
GL_COMMIT=	c39a8c651834d43a0065a32eef31d6982b369af8

NO_ARCH=	yes

SHEBANG_REGEX=	./src/.*\.sh$$

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk_next \
		--disable-flashback \
		--disable-telegram \
		--disable-tweetdeck \
		--disable-airforsteam

USE_GNOME=	gdkpixbuf2 gtk30 libxml2

OPTIONS_DEFINE=	CINNAMON DOCS GNOME METACITY OPENBOX PARALLEL PLANK XFCE
OPTIONS_DEFAULT=	CINNAMON GNOME METACITY OPENBOX PARALLEL PLANK XFCE
OPTIONS_SUB=	yes

CINNAMON_DESC=	Enable Cinnamon support
CINNAMON_CONFIGURE_ENABLE=	cinnamon
CINNAMON_IMPLIES=	METACITY
GNOME_DESC=	Enable Gnome support
GNOME_CONFIGURE_ENABLE=	gnome
METACITY_DESC=	Enable Metacity support
OPENBOX_DESC=	Enable Openbox support
OPENBOX_CONFIGURE_ENABLE=	openbox
PARALLEL_DESC=	Enable parallel build
PARALLEL_BUILD_DEPENDS=	parallel:sysutils/parallel
PARALLEL_CONFIGURE_ENABLE=	parallel
PLANK_DESC=	Enale Plank support
PLANK_CONFIGURE_ENABLE=	plank
XFCE_DESC=	Enable Xfce support
XFCE_CONFIGURE_ENABLE=	xfce

PORTDOCS=	README.md README.window-list

post-extract:
	${CP} ${WRKSRC}/src/shell/sass/gnome-shell/README.window-list ${WRKSRC}

post-patch:
	(cd ${WRKSRC} && \
	${FIND} . -type f -iregex '${SHEBANG_REGEX}' \
		-exec ${SED} -i '' -e "s/sed -i/& ''/g" {} ';')
	${REINPLACE_CMD} -e 's|/usr|${LOCALBASE}|; s|$${prefix}|${PREFIX}|' \
		${WRKSRC}/README.window-list

post-install:
	${RM} ${STAGEDIR}${PREFIX}/share/themes/Plata/COPYING
	${RM} ${STAGEDIR}${PREFIX}/share/themes/Plata/LICENSE_CC_BY_SA4
	${RM} ${STAGEDIR}${PREFIX}/share/themes/Plata/gnome-shell/extensions/window-list/README

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
