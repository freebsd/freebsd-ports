# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/sysutils/policykit/Makefile,v 1.22 2008/08/21 21:53:00 mezz Exp $

PORTNAME=	policykit
PORTVERSION=	0.9
PORTREVISION=	7
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://hal.freedesktop.org/releases/
DISTNAME=	PolicyKit-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Framework for controlling access to system-wide components

LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libexpat.so:${PORTSDIR}/textproc/expat2

USERS=		polkit
GROUPS=		polkit

USES=		gmake libtool pathfix pkgconfig
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
BUILD_DEPENDS=	${LOCALBASE}/share/sgml/docbook/4.1:${PORTSDIR}/textproc/docbook-sgml \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl
USE_GNOME+=	libxslt:build

PLIST_SUB+=	MANPAGES=""
.else
CONFIGURE_ARGS+=--disable-man-pages
PLIST_SUB+=	MANPAGES="@comment "
.endif

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/PolicyKit
	if [ ! -f ${PREFIX}/etc/PolicyKit/PolicyKit.conf ]; then \
		${INSTALL_DATA} ${WRKSRC}/data/PolicyKit.conf \
			${STAGEDIR}${PREFIX}/etc/PolicyKit/PolicyKit.conf ; \
	fi
	${INSTALL_DATA} ${WRKSRC}/data/PolicyKit.conf \
		${STAGEDIR}${PREFIX}/etc/PolicyKit/PolicyKit.conf.dist
	# this file is used for reloading rules, handle it in the plist.
	@${RM} ${STAGEDIR}/var/lib/misc/PolicyKit.reload
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so.*

.include <bsd.port.mk>
