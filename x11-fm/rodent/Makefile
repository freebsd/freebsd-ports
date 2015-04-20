# Created by: Jens K. Loewe <bsd@tuxproject.de>
# $FreeBSD$

PORTNAME=	rodent
PORTVERSION=	5.2.9
PORTREVISION=	2
CATEGORIES=	x11-fm
MASTER_SITES=	SF/xffm/rodent/

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Fast, small and powerful file manager

LICENSE=	GPLv3

BUILD_DEPENDS=	gawk:${PORTSDIR}/lang/gawk \
		bash:${PORTSDIR}/shells/bash \
		intltoolize:${PORTSDIR}/textproc/intltool
LIB_DEPENDS=	libcairo.so:${PORTSDIR}/graphics/cairo \
		libmagic.so:${PORTSDIR}/sysutils/file \
		librfm.so:${PORTSDIR}/x11-fm/librfm

USES=		desktop-file-utils gmake libtool:keepla pkgconfig tar:bzip2 shebangfix
USE_GNOME=	glib20 gtk20 librsvg2 libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--docdir=${DOCSDIR}
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
SHEBANG_FILES=	configure

PORTDOCS=	*

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

#post-patch:
#	${REINPLACE_CMD} -e 's,^\(docdir = \).*,\1${DOCSDIR},' \
#		${WRKSRC}/Build/share/Makefile.in

.for a in ia64 powerpc sparc63
BROKEN_${a}=		Does not compile on ia64, powerpc, or sparc64
.endfor

.include <bsd.port.mk>
