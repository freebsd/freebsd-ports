# Created by: Anders F Bjorklund <afb@users.sourceforge.net>
# $FreeBSD$
#   $MCom: ports/trunk/ports-mgmt/packagekit/Makefile 18965 2013-12-20 11:02:42Z kwm $

PORTNAME=	packagekit
PORTVERSION=	0.8.9
CATEGORIES=	ports-mgmt sysutils
MASTER_SITES=	http://www.packagekit.org/releases/
DISTNAME=	PackageKit-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A DBUS packaging abstraction layer

BUILD_DEPENDS=	${LOCALBASE}/bin/docbook2man:${PORTSDIR}/textproc/docbook-utils
LIB_DEPENDS=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo \
		libpolkit-gobject-1.so:${PORTSDIR}/sysutils/polkit
RUN_DEPENDS=	lsof:${PORTSDIR}/sysutils/lsof

USE_XZ=		yes
USES=		gettext gmake iconv pathfix shared-mime-info
USE_GNOME=	glib20 intltool introspection
USE_LDCONFIG=	yes
USE_SQLITE=	3
USE_PYTHON=	-2.7
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lexecinfo
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
BUILD_DEPENDS+=	${LOCALBASE}/share/sgml/docbook/4.1/dtd/catalog:${PORTSDIR}/textproc/docbook-410 \
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
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/packagekit-backend/libpk*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/packagekit-plugins/libpk*.so

.include <bsd.port.mk>
