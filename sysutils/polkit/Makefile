# Created by: Koop Mast<kwm@FreeBSD.org>

PORTNAME=	polkit
PORTVERSION=	0.120
PORTREVISION=	2
CATEGORIES=	sysutils gnome
MASTER_SITES=	https://www.freedesktop.org/software/polkit/releases/

PATCH_SITES=	https://gitlab.freedesktop.org/${PORTNAME}/${PORTNAME}/-/commit/
PATCHFILES+=	e7f3d9e8341d.patch:-p1 # https://gitlab.freedesktop.org/polkit/polkit/-/merge_requests/99
PATCHFILES+=	a2bf5c9c83b6.patch:-p1 # https://gitlab.freedesktop.org/polkit/polkit/-/merge_requests/104 (CVE-2021-4034)

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Framework for controlling access to system-wide components

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libdbus-1.so:devel/dbus \
		libmozjs-91.so:lang/spidermonkey91

USERS=		polkitd
GROUPS=		polkitd

USES=		compiler:c++11-lib cpe gettext gnome libtool localbase meson \
		pathfix pkgconfig shebangfix
USE_GNOME=	glib20 intltool introspection:build
SHEBANG_FILES=	${WRKSRC}/src/polkitbackend/toarray.pl
USE_LDCONFIG=	yes
CPE_VENDOR=	polkit_project

MESON_ARGS=	-Dpam_include=system \
		-Dpolkitd_user=${USERS} \
		-Dexamples=false \
		-Dsession_tracking=ConsoleKit \
		-Dtests=false \
		-Dintrospection=true \
		-Dlocalstatedir=/var \
		-Dgtk_doc=false

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		MANPAGES

MANPAGES_BUILD_DEPENDS=	docbook-sgml>=4.5:textproc/docbook-sgml \
			docbook-xsl>=1.76:textproc/docbook-xsl
MANPAGES_USE=		gnome=libxslt:build
MANPAGES_MESON_TRUE=	man

OPTIONS_SUB=		yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/|${PREFIX}/bin/|g' \
		${WRKSRC}/docs/man/pkexec.xml \
		${WRKSRC}/src/examples/org.freedesktop.policykit.examples.pkexec.policy.in
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${PREFIX}|g' \
		${WRKSRC}/docs/man/polkit.xml

post-install:
	@${MKDIR} ${STAGEDIR}/var/lib/polkit-1 \
		  ${STAGEDIR}${PREFIX}/share/polkit-1/rules.d
.for i in 10-vendor.d 20-org.d 30-site.d 50-local.d 90-mandatory.d
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/polkit-1/localauthority/${i}
	${MKDIR} ${STAGEDIR}/var/lib/polkit-1/localauthority/${i}
.endfor

.include <bsd.port.post.mk>
