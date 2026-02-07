PORTNAME=	rodent
PORTVERSION=	5.3.16.3
PORTREVISION=	7
CATEGORIES=	x11-fm
MASTER_SITES=	SF/xffm/${PORTVERSION}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Fast, small, and powerful file manager
WWW=		http://xffm.org/

LICENSE=	GPLv3

BUILD_DEPENDS=	bash:shells/bash \
		gawk:lang/gawk \
		intltoolize:textproc/intltool
LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libmagic.so:sysutils/file \
		librfm.so:x11-fm/librfm

USES=		desktop-file-utils gmake gnome libtool:keepla pkgconfig \
		shebangfix tar:bzip2
USE_GNOME=	glib20 gtk20 librsvg2 libxml2
USE_LDCONFIG=	yes

SHEBANG_FILES=	configure

GNU_CONFIGURE=			yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=			--docdir=${DOCSDIR}
INSTALL_TARGET=			install-strip

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
