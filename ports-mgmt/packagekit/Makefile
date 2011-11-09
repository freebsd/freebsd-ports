# New ports collection makefile for:	packagekit
# Date created:				15 Aug 2009
# Whom:					Anders F Bjorklund <afb@users.sourceforge.net>
#
# $FreeBSD$
#   $MCom: ports/ports-mgmt/packagekit/Makefile,v 1.26 2010/10/10 15:49:51 marcus Exp $

PORTNAME=	PackageKit
PORTVERSION=	0.6.11
PORTREVISION?=	1
CATEGORIES=	ports-mgmt sysutils
MASTER_SITES=	http://www.packagekit.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	A DBUS packaging abstraction layer

BUILD_DEPENDS=	${LOCALBASE}/bin/docbook2man:${PORTSDIR}/textproc/docbook-utils \
		${LOCALBASE}/share/gir-1.0/GLib-2.0.gir:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo \
		sqlite3.8:${PORTSDIR}/databases/sqlite3 \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		polkit-gobject-1.0:${PORTSDIR}/sysutils/polkit \
		ck-connector.0:${PORTSDIR}/sysutils/consolekit
RUN_DEPENDS=	lsof:${PORTSDIR}/sysutils/lsof \
		${LOCALBASE}/share/gir-1.0/GLib-2.0.gir:${PORTSDIR}/devel/gobject-introspection \
		${LOCALBASE}/share/mime/magic:${PORTSDIR}/misc/shared-mime-info

USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	glib20 intltool
USE_ICONV=	yes
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
OPTIONS=PORTS "Use portupgrade for management, dummy if disabled" on \
	PORTDOCS "Build documentation" on
# gtk module seems to be broken/disabled/gone?
#	GTK20 "Enable GTK+ modules" off \

.if defined(NO_INSTALL_MANPAGES)
CONFIGURE_ARGS+=--disable-man-pages
.else
BUILD_DEPENDS+=	${LOCALBASE}/share/sgml/docbook/4.1/dtd/catalog:${PORTSDIR}/textproc/docbook-410 \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl
MAN1=	pkcon.1 pkmon.1 pkgenpack.1 pk-debuginfo-install.1
.endif
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_PORTS)
RUN_DEPENDS+=	portupgrade:${PORTSDIR}/ports-mgmt/portupgrade
USE_RUBY=	yes
CONFIGURE_ARGS+=--enable-ports --with-default-backend=ports
PLIST_SUB+=	PORTS=""
.else
CONFIGURE_ARGS+=--disable-ports --with-default-backend=dummy
PLIST_SUB+=	PORTS="@comment "
.endif

#.if defined(WITH_GTK)
#USE_GNOME+=	gtk20
#CONFIGURE_ARGS+=--enable-gtk-module
#PLIST_SUB+=	GTK=""
#.else
CONFIGURE_ARGS+=--disable-gtk-module
PLIST_SUB+=	GTK="@comment "
#.endif

.if defined(SLAVEPORT)
LIB_DEPENDS+=	packagekit-glib2.14:${PORTSDIR}/ports-mgmt/packagekit

.if ${SLAVEPORT}=="qt4"
CONFIGURE_ARGS+=--enable-qt
LIB_DEPENDS+=	cppunit-1.12.1:${PORTSDIR}/devel/cppunit
USE_QT_VER+=	4
QT_COMPONENTS+=	dbus gui xml sql moc_build
.include "${PORTSDIR}/Mk/bsd.qt.mk"
.endif
.else
CONFIGURE_ARGS+=--disable-qt
.endif

post-patch:
	@${REINPLACE_CMD} -E -e 's/.*WARNINGFLAGS_CPP.*-Werror/#$$&/' \
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

.include <bsd.port.post.mk>
