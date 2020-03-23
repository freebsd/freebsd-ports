# $FreeBSD$

PORTNAME=	materia-gtk-theme
DISTVERSIONPREFIX=	v
DISTVERSION=	20200320
CATEGORIES=	x11-themes

MAINTAINER=	tagattie@yandex.com
COMMENT=	Material Design theme for GNOME/GTK+ based desktop environments

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	gtk-murrine-engine>0:x11-themes/gtk-murrine-engine \
		gnome-themes-extra>0:x11-themes/gnome-themes-extra

USES=		shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	nana-4
GH_PROJECT=	materia-theme

NO_ARCH=	yes
NO_BUILD=	yes

PORTDOCS=	COPYING README.md
SHEBANG_FILES=	install.sh

OPTIONS_DEFINE=	DOCS GNOMESHELL
OPTIONS_DEFAULT=	GNOMESHELL
OPTIONS_SUB=	yes

# the install script needs gnome-shell to determine its
# version, but not all gtk themes users are Gnome users,
# and keeping gnome-shell as standard build time dependency
# would force non-Gnome users to build 110+ gnome ports just
# to get the theme.
GNOMESHELL_DESC=		Add Gnome-Shell theme version
GNOMESHELL_BUILD_DEPENDS=	gnome-shell:x11/gnome-shell
GNOMESHELL_PORTDOCS=		gnome-shell.README.md

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/themes
	${WRKSRC}/install.sh --dest ${STAGEDIR}${PREFIX}/share/themes
	@${MV} ${WRKSRC}/src/gnome-shell/README.md \
		${WRKSRC}/gnome-shell.README.md
	@${RM} ${STAGEDIR}${PREFIX}/share/themes/*/COPYING
	@${RM} ${STAGEDIR}${PREFIX}/share/themes/*/gnome-shell/README.md

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && \
		${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

post-install-GNOMESHELL-off:
	@${RM} -R ${STAGEDIR}${PREFIX}/share/themes/*/gnome-shell

.include <bsd.port.mk>
