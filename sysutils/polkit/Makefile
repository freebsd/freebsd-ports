# Created by: Koop Mast<kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/sysutils/polkit/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	polkit
PORTVERSION=	0.105
PORTREVISION=	2
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://www.freedesktop.org/software/polkit/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Framework for controlling access to system-wide components

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2
RUN_DEPENDS=	dbus-launch:${PORTSDIR}/devel/dbus

NO_STAGE=	yes
USE_GNOME=	glib20 intlhack gnomehier introspection
USES=		gettext gmake pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--with-authfw=pam \
		--with-pam-include=system \
		--with-os-type=freebsd \
		--disable-systemd \
		--enable-introspection \
		--localstatedir=/var
CONFIGURE_ENV=	GTKDOC="false"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	MANPAGES

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMANPAGES}
BUILD_DEPENDS+=	${LOCALBASE}/share/sgml/docbook/4.1/dtd/catalog:${PORTSDIR}/textproc/docbook-410 \
    		xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl

MAN1=		pkaction.1 pkcheck.1 pkexec.1 pkttyagent.1
MAN8=		pklocalauthority.8 polkit.8 polkitd.8
.else
CONFIGURE_ARGS+=--disable-man-pages
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/|${PREFIX}/bin/|g' \
		${WRKSRC}/docs/man/pkexec.xml \
		${WRKSRC}/src/examples/org.freedesktop.policykit.examples.pkexec.policy.in

post-install:
	${MKDIR} ${PREFIX}/etc/dbus-1/system.d/
	if [ ! -f ${PREFIX}/etc/dbus-1/system.d/org.freedesktop.PolicyKit1.conf ]; then \
		${INSTALL_DATA} ${WRKSRC}/data/org.freedesktop.PolicyKit1.conf \
			${PREFIX}/etc/dbus-1/system.d/org.freedesktop.PolicyKit1.conf ; \
	fi
	${INSTALL_DATA} ${WRKSRC}/data/org.freedesktop.PolicyKit1.conf \
		${PREFIX}/etc/dbus-1/system.d/org.freedesktop.PolicyKit1.conf.dist
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.mk>
