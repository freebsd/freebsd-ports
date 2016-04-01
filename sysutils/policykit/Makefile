# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/sysutils/policykit/Makefile,v 1.22 2008/08/21 21:53:00 mezz Exp $

PORTNAME=	policykit
PORTVERSION=	0.9
PORTREVISION=	10
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://hal.freedesktop.org/releases/
DISTNAME=	PolicyKit-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Framework for controlling access to system-wide components

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libexpat.so:textproc/expat2

USERS=		polkit
GROUPS=		polkit

USES=		gettext gmake libtool:keepla pathfix pkgconfig
USE_GNOME=	glib20 intlhack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--with-pam-include=system \
		--with-os-type=freebsd \
		--localstatedir=/var \
		--with-polkit-user=polkit \
		--with-polkit-group=polkit
CONFIGURE_ENV=	GTKDOC="false"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMANPAGES}
BUILD_DEPENDS=	docbook-sgml>0:textproc/docbook-sgml \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl
USE_GNOME+=	libxslt:build

PLIST_SUB+=	MANPAGES=""
.else
CONFIGURE_ARGS+=--disable-man-pages
PLIST_SUB+=	MANPAGES="@comment "
.endif

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/PolicyKit
	${INSTALL_DATA} ${WRKSRC}/data/PolicyKit.conf \
		${STAGEDIR}${PREFIX}/etc/PolicyKit/PolicyKit.conf.sample
	# this file is used for reloading rules, handle it in the plist.
	@${RM} ${STAGEDIR}/var/lib/misc/PolicyKit.reload
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so.*

.include <bsd.port.mk>
