# Created by: Jens K. Loewe <bsd@tuxproject.de>
# $FreeBSD$

PORTNAME=	rodent
PORTVERSION=	5.3.16.3
PORTREVISION=	1
CATEGORIES=	x11-fm
MASTER_SITES=	SF/xffm/${PORTVERSION}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Fast, small, and powerful file manager

LICENSE=	GPLv3

BUILD_DEPENDS=	gawk:lang/gawk \
		bash:shells/bash \
		intltoolize:textproc/intltool
LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libmagic.so.1:sysutils/file \
		librfm.so:x11-fm/librfm

USES=		desktop-file-utils gmake gnome libtool:keepla pkgconfig \
		shebangfix tar:bzip2
USE_GNOME=	glib20 gtk20 librsvg2 libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--docdir=${DOCSDIR}
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
SHEBANG_FILES=	configure

PORTDOCS=	*

OPTIONS_DEFINE=	NLS DOCS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

#post-patch:
#	${REINPLACE_CMD} -e 's,^\(docdir = \).*,\1${DOCSDIR},' \
#		${WRKSRC}/Build/share/Makefile.in

.include <bsd.port.mk>
