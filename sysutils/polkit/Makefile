# Created by: Koop Mast<kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	polkit
PORTVERSION=	0.114
PORTREVISION=	3
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://www.freedesktop.org/software/polkit/releases/

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Framework for controlling access to system-wide components

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libmozjs-52.so:lang/spidermonkey52
RUN_DEPENDS=	dbus-launch:devel/dbus

USERS=		polkitd
GROUPS=		polkitd

USES=		compiler:c++11-lib gettext gmake gnome libtool localbase \
		pathfix pkgconfig shebangfix
USE_GNOME=	glib20 intlhack introspection:build
SHEBANG_FILES=	${WRKSRC}/src/polkitbackend/toarray.pl
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-gtk-doc-html \
		--without-html-dir \
		--with-authfw=pam \
		--with-pam-include=system \
		--with-os-type=freebsd \
		--with-polkitd-user=${USERS} \
		--disable-static \
		--disable-examples \
		--disable-libsystemd-login \
		--disable-libelogind \
		--disable-test \
		--enable-introspection=yes \
		--localstatedir=/var
#MAKE_JOBS_UNSAFE=yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	MANPAGES
MANPAGES_BUILD_DEPENDS=	docbook-sgml>=4.5:textproc/docbook-sgml \
		docbook-xsl>=1.76:textproc/docbook-xsl
MANPAGES_USE=	gnome=libxslt:build
MANPAGES_CONFIGURE_ENABLE=	man-pages
OPTIONS_SUB=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/|${PREFIX}/bin/|g' \
		${WRKSRC}/docs/man/pkexec.xml \
		${WRKSRC}/src/examples/org.freedesktop.policykit.examples.pkexec.policy.in
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${PREFIX}|g' \
		${WRKSRC}/docs/man/polkit.xml

post-install:
	@${MKDIR} ${STAGEDIR}/var/lib/polkit-1
	${INSTALL_DATA} ${WRKSRC}/data/org.freedesktop.PolicyKit1.conf \
		${STAGEDIR}${PREFIX}/etc/dbus-1/system.d/org.freedesktop.PolicyKit1.conf.sample
.for i in 10-vendor.d 20-org.d 30-site.d 50-local.d 90-mandatory.d
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/polkit-1/localauthority/${i}
	${MKDIR} ${STAGEDIR}/var/lib/polkit-1/localauthority/${i}
.endfor

.include <bsd.port.post.mk>
