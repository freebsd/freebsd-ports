PORTNAME=	gigolo
PORTVERSION=	0.6.0
CATEGORIES=	sysutils
MASTER_SITES=	XFCE/apps

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Frontend to easily manage filesystem connections
WWW=		https://docs.xfce.org/apps/gigolo/start

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-XML-Parser>=0:textproc/p5-XML-Parser

USES=		gettext-tools gnome meson pkgconfig tar:xz xfce xorg
USE_GNOME=	gtk30 gvfs
USE_XORG=	x11

PORTDOCS=	AUTHORS ChangeLog COPYING NEWS README.md THANKS TODO

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
