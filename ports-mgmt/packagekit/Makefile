# Created by: Anders F Bjorklund <afb@users.sourceforge.net>
# $FreeBSD$
#   $MCom: ports/ports-mgmt/packagekit/Makefile,v 1.26 2010/10/10 15:49:51 marcus Exp $

PORTNAME=	PackageKit
PORTVERSION=	0.6.11
PORTREVISION?=	6
CATEGORIES=	ports-mgmt sysutils
MASTER_SITES=	http://www.packagekit.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	DBUS packaging abstraction layer

BUILD_DEPENDS=	${LOCALBASE}/bin/docbook2man:${PORTSDIR}/textproc/docbook-utils
LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libpolkit-gobject-1.so:${PORTSDIR}/sysutils/polkit \
		libck-connector.so:${PORTSDIR}/sysutils/consolekit
RUN_DEPENDS=	lsof:${PORTSDIR}/sysutils/lsof

USES=		execinfo gettext gmake iconv libtool pathfix pkgconfig \
		python:build shared-mime-info
USE_GNOME=	glib20 intltool gnomehier introspection
USE_SQLITE=	3
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lexecinfo
CONFIGURE_ARGS+=--with-security-framework=polkit \
		--localstatedir=/var \
		--disable-static \
		--disable-gtk-doc \
		--disable-managed \
		--disable-browser-plugin \
		--disable-gstreamer-plugin \
		--disable-networkmanager \
		--disable-connman
INSTALL_TARGET=	install-strip

MAKE_JOBS_UNSAFE=yes

.if !defined(SLAVEPORT)
OPTIONS_DEFINE=	PORTS MANPAGES
OPTIONS_DEFAULT=PORTS
PORTS_DESC=Use portupgrade for management, dummy if disabled

.include <bsd.port.options.mk>

. if ${PORT_OPTIONS:MMANPAGES}
BUILD_DEPENDS+=	${LOCALBASE}/share/sgml/docbook/4.1:${PORTSDIR}/textproc/docbook-sgml \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl
PLIST_SUB+=	MAN=''
. else
CONFIGURE_ARGS+=--disable-man-pages
PLIST_SUB+=	MAN='@comment '
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
LIB_DEPENDS+=	libpackagekit-glib2.so:${PORTSDIR}/ports-mgmt/packagekit

CONFIGURE_ARGS+=--enable-qt
LIB_DEPENDS+=	libcppunit.so:${PORTSDIR}/devel/cppunit
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
	    	${STAGEDIR}${PREFIX}/share/PackageKit/transactions.db
.endif

.include <bsd.port.mk>
