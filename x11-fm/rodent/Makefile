# Created by: Jens K. Loewe <bsd@tuxproject.de>
# $FreeBSD$

PORTNAME=	rodent
PORTVERSION=	4.8.0
CATEGORIES=	x11-fm
MASTER_SITES=	SF/xffm/${PORTVERSION}/

MAINTAINER=	rodrigo@bebik.net
COMMENT=	Fast, small and powerful file manager

LICENSE=	GPLv3

BUILD_DEPENDS=	gawk:${PORTSDIR}/japanese/gawk \
		bash:${PORTSDIR}/shells/bash \
		intltoolize:${PORTSDIR}/textproc/intltool
LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2 \
		glib-2:${PORTSDIR}/devel/glib20 \
		cairo:${PORTSDIR}/graphics/cairo \
		rsvg-2:${PORTSDIR}/graphics/librsvg2 \
		gtk-x11-2:${PORTSDIR}/x11-toolkits/gtk20 \
		magic:${PORTSDIR}/sysutils/file

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--docdir=${DOCSDIR}
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

PORTDOCS=	*

MAN1=		fgr.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e 's,^\(docdir = \).*,\1${DOCSDIR},' \
		${WRKSRC}/Build/share/Makefile.in

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

.include <bsd.port.mk>
