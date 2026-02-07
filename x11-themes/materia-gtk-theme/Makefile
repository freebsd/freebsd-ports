PORTNAME=	materia-gtk-theme
DISTVERSIONPREFIX=	v
DISTVERSION=	20210322
PORTREVISION=	2
CATEGORIES=	x11-themes

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Material Design theme for GNOME/GTK based desktop environments
WWW=		https://github.com/nana-4/materia-theme

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	sassc:textproc/sassc
RUN_DEPENDS=	gtk-murrine-engine>0:x11-themes/gtk-murrine-engine \
		gnome-themes-extra>0:x11-themes/gnome-themes-extra

USES=		gnome meson
USE_GNOME=	gtk30

USE_GITHUB=	yes
GH_ACCOUNT=	nana-4
GH_PROJECT=	materia-theme

NO_ARCH=	yes

PORTDOCS=	CHANGELOG.md INSTALL_GDM_THEME.md README.md

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

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/share/themes/*/COPYING
	@${RM} ${STAGEDIR}${PREFIX}/share/themes/*/INSTALL_GDM_THEME.md

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-GNOMESHELL-off:
	@${RM} -R ${STAGEDIR}${PREFIX}/share/themes/*/gnome-shell

.include <bsd.port.mk>
