# Ports collection Makefile for:	rodent
# Date created:				16 March 2012
# Whom:					Jens K. Loewe <bsd@tuxproject.de>
#
# $FreeBSD$
#

PORTNAME=	rodent
PORTVERSION=	4.7.4
CATEGORIES=	x11-fm
MASTER_SITES=	SF/xffm/${PORTVERSION}/

MAINTAINER=	bsd@tuxproject.de
COMMENT=	A fast, small and powerful file manager

LICENSE=	GPLv3

BUILD_DEPENDS=	gawk:${PORTSDIR}/japanese/gawk \
		bash:${PORTSDIR}/shells/bash \
		intltoolize:${PORTSDIR}/textproc/intltool
LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2 \
		glib-2.0.0:${PORTSDIR}/devel/glib20 \
		cairo.2:${PORTSDIR}/graphics/cairo \
		rsvg-2:${PORTSDIR}/graphics/librsvg2 \
		gtk-x11-2:${PORTSDIR}/x11-toolkits/gtk20 \
		magic.1:${PORTSDIR}/sysutils/file

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--docdir=${DOCSDIR}
USE_GMAKE=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

PORTDOCS=	*

MAN1=		fgr.1

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e 's,^\(docdir = \).*,\1${DOCSDIR},' \
		${WRKSRC}/Build/share/Makefile.in

.include <bsd.port.mk>
