# Created by: Anders F Bjorklund <afb@users.sourceforge.net>
# $FreeBSD$
#   $MCom: ports/trunk/ports-mgmt/packagekit/Makefile 19804 2014-08-13 14:55:11Z kwm $

PORTNAME=	packagekit
PORTVERSION=	0.8.9
CATEGORIES=	ports-mgmt sysutils
MASTER_SITES=	http://www.packagekit.org/releases/
DISTNAME=	PackageKit-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A DBUS packaging abstraction layer

BUILD_DEPENDS=	docbook2man:${PORTSDIR}/textproc/docbook-utils
LIB_DEPENDS=	libpolkit-gobject-1.so:${PORTSDIR}/sysutils/polkit
RUN_DEPENDS=	lsof:${PORTSDIR}/sysutils/lsof

USES=		execinfo gettext gmake iconv pathfix pkgconfig \
		python:2 shared-mime-info tar:xz
USE_GNOME=	glib20 intltool introspection
USE_LDCONFIG=	yes
USE_SQLITE=	3
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lexecinfo
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS+=--with-security-framework=polkit \
		--localstatedir=/var \
		--disable-gtk-doc \
		--disable-browser-plugin \
		--disable-gstreamer-plugin \
		--disable-networkmanager \
		--disable-systemd \
		--disable-bash-completion \
		--disable-connman

OPTIONS_DEFINE=	MANPAGES

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMANPAGES} || defined(PACKAGE_BUILDING)
BUILD_DEPENDS+=	${LOCALBASE}/share/sgml/docbook/4.1:${PORTSDIR}/textproc/docbook-sgml \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl
USE_GNOME+=	libxslt:build
PLIST_SUB+=	MAN=""
.else
CONFIGURE_ARGS+=--disable-man-pages
PLIST_SUB+=	MAN="@comment "
.endif

# IMO we should just enable the new (not writted pkgng backend) on systems
# where pkgng is enabled.

#.if ${PORT_OPTIONS:MPORTS_BACKEND}
#LIB_DEPENDS+=	pkg:${PORTSDIR}/ports-mgmt/pkg
#CONFIGURE_ARGS+=--enable-ports --with-default-backend=ports
#PLIST_SUB+=	PORTS=""
#.else
CONFIGURE_ARGS+=--disable-ports --with-default-backend=dummy
PLIST_SUB+=	PORTS="@comment "
#.endif

# gtk+3 module
CONFIGURE_ARGS+=--disable-gtk-module
PLIST_SUB+=	GTK="@comment "

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/plugins/pk-lsof.c

post-install:
	@${MKDIR} ${STAGEDIR}/var/cache/PackageKit/downloads

.include <bsd.port.mk>
