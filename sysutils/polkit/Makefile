# Created by: Koop Mast<kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/sysutils/polkit/Makefile 19013 2014-03-08 07:50:57Z kwm $

PORTNAME=	polkit
PORTVERSION=	0.105
PORTREVISION=	2
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://www.freedesktop.org/software/polkit/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Framework for controlling access to system-wide components

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2
RUN_DEPENDS=	dbus-launch:${PORTSDIR}/devel/dbus

USE_GNOME=	glib20 intlhack gnomehier introspection
USES=		gettext gmake libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--with-authfw=pam \
		--with-pam-include=system \
		--with-os-type=freebsd \
		--disable-systemd \
		--enable-introspection \
		--localstatedir=/var
MAKE_JOBS_UNSAFE=yes
CONFIGURE_ENV=	GTKDOC="false"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	MANPAGES

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMANPAGES}
BUILD_DEPENDS+=	${LOCALBASE}/share/sgml/docbook/4.1:${PORTSDIR}/textproc/docbook-sgml \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl

USE_GNOME+=	libxslt:build
PLIST_SUB+=	MANPAGES=""
.else
CONFIGURE_ARGS+=--disable-man-pages
PLIST_SUB+=	MANPAGES="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/|${PREFIX}/bin/|g' \
		${WRKSRC}/docs/man/pkexec.xml \
		${WRKSRC}/src/examples/org.freedesktop.policykit.examples.pkexec.policy.in

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/dbus-1/system.d/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/polkit-1/rules.d/
	${INSTALL_DATA} ${WRKSRC}/data/org.freedesktop.PolicyKit1.conf \
		${STAGEDIR}${PREFIX}/etc/dbus-1/system.d/org.freedesktop.PolicyKit1.conf.dist
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/polkit-1/extensions/lib*.so

.include <bsd.port.mk>
