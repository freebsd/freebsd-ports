# Created by: Nicola Stanislao Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	adapta-gtk-theme
PORTVERSION=	3.91.2.152
PORTREVISION=	1
CATEGORIES=	x11-themes

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Adaptive Gtk+ theme based on Material Design Guidelines

LICENSE=	GPLv2 CC-BY-SA-4.0
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_CC-BY-SA-4.0=	${WRKSRC}/LICENSE_CC_BY_SA4

BUILD_DEPENDS=	gsed:textproc/gsed \
		inkscape:graphics/inkscape \
		bash:shells/bash \
		sassc:textproc/sassc
RUN_DEPENDS=	noto>=1.0.5:x11-fonts/noto \
		roboto-fonts-ttf>=2.134:x11-fonts/roboto-fonts-ttf

CHROME_CONFIGURE_ENABLE=	chrome
CHROME_DESC=	Support for Chrome(ium) browser
CINNAMON_CONFIGURE_ENABLE=	cinnamon
CINNAMON_DESC=	Support for Cinnamon Desktop Environment
CINNAMON_IMPLIES=	METACITY
CONFIGURE_ARGS=	--enable-gtk_legacy \
		--disable-flashback \
		--disable-gtk_next \
		--disable-plank \
		--disable-telegram \
		--disable-unity

DOCS_MAKE_ENV=	ADAPTA_DOCS=yes

GH_ACCOUNT=	adapta-project
GNOMESHELL_BUILD_DEPENDS=	gnome-shell:x11/gnome-shell
GNOMESHELL_CONFIGURE_ENABLE=	gnome
GNOMESHELL_DESC=	Support for Gnome-Shell Desktop Environment

GNU_CONFIGURE=	yes

MATE_CONFIGURE_ENABLE=	mate
MATE_DESC=	Support for Mate Desktop Environment
MATE_IMPLIES=	METACITY
METACITY_DESC=	Support for metacity Window Manager

OPENBOX_CONFIGURE_ENABLE=	openbox
OPENBOX_DESC=	Support for Openbox Desktop Environment
OPTIONS_DEFAULT=	CHROME CINNAMON GNOMESHELL MATE METACITY OPENBOX PARALLEL XFCE
OPTIONS_DEFINE=	CHROME CINNAMON DOCS GNOMESHELL MATE METACITY OPENBOX PARALLEL XFCE
OPTIONS_SUB=	yes

PARALLEL_BUILD_DEPENDS=	parallel:sysutils/parallel
PARALLEL_DESC=	parallel-build support

SHEBANG_REGEX=	'.*\.sh$$'

USES=		autoreconf gmake pathfix pkgconfig shebangfix
USE_GITHUB=	yes
USE_GNOME=	gdkpixbuf2 glib20 librsvg2 libxml2

XFCE_CONFIGURE_ENABLE=	xfce
XFCE_DESC=	Support for XFce Desktop Environment

# use textproc/gsed
post-patch:
	@(cd ${WRKSRC} && \
	${FIND} . -type f -iregex '${SHEBANG_REGEX}' \
		-exec ${SED} -i '' -e 's,sed -i,${LOCALBASE}/bin/g&,g' {} ";")

.include <bsd.port.mk>
