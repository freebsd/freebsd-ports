PORTNAME=	xfburn
PORTVERSION=	0.8.0
CATEGORIES=	sysutils
MASTER_SITES=	XFCE/apps
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	CD/DVD burning tool for Xfce
WWW=		https://docs.xfce.org/apps/xfburn/start

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/share/xml/docbook/4.4/catalog.xml:textproc/docbook-xml \
		${LOCALBASE}/share/xsl/docbook/html/refentry.xsl:textproc/docbook-xsl \
		itstool:textproc/itstool \
		xsltproc:textproc/libxslt
LIB_DEPENDS=	libburn.so:devel/libburn \
		libisofs.so:devel/libisofs
RUN_DEPENDS=	cdrdao:sysutils/cdrdao

USES=		compiler:c11 desktop-file-utils gettext-tools gnome meson \
		pkgconfig tar:bzip2 xfce
USE_GNOME=	glib20 gtk30
USE_XFCE=	libexo

MESON_ARGS=	-Dgudev=disabled

OPTIONS_DEFINE=		GSTREAMER NLS
OPTIONS_DEFAULT=	GSTREAMER
OPTIONS_SUB=		yes

GSTREAMER_USES=			gstreamer
GSTREAMER_USE=			GSTREAMER=faac,flac,lame,vorbis,wavpack
GSTREAMER_MESON_ENABLED=	gstreamer

NLS_USES=	gettext-runtime

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
