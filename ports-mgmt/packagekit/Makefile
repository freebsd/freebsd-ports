# Created by: Anders F Bjorklund <afb@users.sourceforge.net>
# $FreeBSD$
#   $MCom: ports/ports-mgmt/packagekit/Makefile,v 1.26 2010/10/10 15:49:51 marcus Exp $

PORTNAME=	PackageKit
PORTVERSION=	0.6.11
PORTREVISION?=	3
CATEGORIES=	ports-mgmt sysutils
MASTER_SITES=	http://www.packagekit.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	DBUS packaging abstraction layer

BUILD_DEPENDS=	${LOCALBASE}/bin/docbook2man:${PORTSDIR}/textproc/docbook-utils \
		${LOCALBASE}/share/gir-1.0/GLib-2.0.gir:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	execinfo:${PORTSDIR}/devel/libexecinfo \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		polkit-gobject-1:${PORTSDIR}/sysutils/polkit \
		ck-connector:${PORTSDIR}/sysutils/consolekit
RUN_DEPENDS=	lsof:${PORTSDIR}/sysutils/lsof \
		${LOCALBASE}/share/gir-1.0/GLib-2.0.gir:${PORTSDIR}/devel/gobject-introspection \
		${LOCALBASE}/share/mime/magic:${PORTSDIR}/misc/shared-mime-info

USES=		gettext gmake iconv
USE_GNOME=	glib20 intltool gnomehier
USE_SQLITE=	3
USE_LDCONFIG=	yes
USE_PYTHON_BUILD=	2.5+
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lexecinfo
CONFIGURE_ARGS+=--with-security-framework=polkit \
		--localstatedir=/var \
		--disable-gtk-doc \
		--disable-managed \
		--disable-browser-plugin \
		--disable-gstreamer-plugin \
		--disable-networkmanager \
		--disable-connman

MAKE_ARGS=	pkgconfigdir="${PREFIX}/libdata/pkgconfig"

MAKE_JOBS_UNSAFE=yes

.if !defined(SLAVEPORT)
OPTIONS_DEFINE=	PORTS MANPAGES
OPTIONS_DEFAULT=PORTS
PORTS_DESC=Use portupgrade for management, dummy if disabled

.include <bsd.port.options.mk>

. if ${PORT_OPTIONS:MMANPAGES}
BUILD_DEPENDS+=	${LOCALBASE}/share/sgml/docbook/4.1/dtd/catalog:${PORTSDIR}/textproc/docbook-410 \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl
MAN1=	pkcon.1 pkmon.1 pkgenpack.1 pk-debuginfo-install.1
. else
CONFIGURE_ARGS+=--disable-man-pages
. endif

. if ${PORT_OPTIONS:MPORTS}
RUN_DEPENDS+=	${LOCALBASE}/sbin/portupgrade:${PORTSDIR}/ports-mgmt/portupgrade
USE_RUBY=	yes
CONFIGURE_ARGS+=--enable-ports --with-default-backend=ports
PLIST_SUB+=	PORTS=""
. else
CONFIGURE_ARGS+=--disable-ports --with-default-backend=dummy
PLIST_SUB+=	PORTS="@comment "
. endif

CONFIGURE_ARGS+=--disable-gtk-module
PLIST_SUB+=	GTK="@comment "

CONFIGURE_ARGS+=--disable-qt

.elif defined(${SLAVEPORT}) && ${SLAVEPORT}=="qt4"
LIB_DEPENDS+=	packagekit-glib2:${PORTSDIR}/ports-mgmt/packagekit

CONFIGURE_ARGS+=--enable-qt
LIB_DEPENDS+=	cppunit-1.12:${PORTSDIR}/devel/cppunit
USE_QT4+=	dbus gui xml sql moc_build
#.include "${PORTSDIR}/Mk/bsd.qt.mk"
.endif

post-patch:
	@${REINPLACE_CMD} -E -e 's/.*WARNINGFLAGS_CPP.*-Werror/#$$&/' \
		-e 's|-DG_DISABLE_DEPRECATED||g' \
		-e 's|-Wmissing-include-dirs||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/pk-lsof.c
	@${REINPLACE_CMD} -e 's|girepositry|girepository|g' \
		${WRKSRC}/lib/packagekit-glib2/Makefile.in
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
	    	'/xsltproc/s|.xsl [$$]? &> /dev|.xsl $$? > /dev|g'

post-install:
.if !defined(SLAVEPORT)
	@${INSTALL_DATA} ${WRKSRC}/data/transactions.db \
	    	${PREFIX}/share/PackageKit/transactions.db
	@-update-mime-database ${PREFIX}/share/mime > /dev/null
.endif

.include <bsd.port.mk>
