PORTNAME=	polkit
DISTVERSION=	124
PORTREVISION=	3
CATEGORIES=	sysutils gnome

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Framework for controlling access to system-wide components
WWW=		https://github.com/${GH_ACCOUNT}/${GH_PROJECT}

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libdbus-1.so:devel/dbus

USERS=		polkitd
GROUPS=		polkitd

USES=		compiler:c++17-lang cpe gettext gnome localbase meson \
		pathfix pkgconfig shebangfix tar:bz2
USE_GNOME=	glib20 intltool introspection:build
SHEBANG_FILES=	${WRKSRC}/src/polkitbackend/toarray.pl
USE_LDCONFIG=	yes
CPE_VENDOR=	polkit_project

USE_GITHUB=	yes
GH_ACCOUNT=	polkit-org

MESON_ARGS=	-Dpam_include=system \
		-Dpam_prefix='etc/pam.d' \
		-Dpolkitd_user=${USERS} \
		-Dexamples=false \
		-Dsession_tracking=ConsoleKit \
		-Dtests=false \
		-Dintrospection=true \
		-Dlocalstatedir=/var \
		-Dgtk_doc=false

OPTIONS_DEFINE=		MANPAGES
OPTIONS_DEFAULT=	DUKTAPE

OPTIONS_SINGLE=		JS
OPTIONS_SINGLE_JS=	DUKTAPE SPIDERMONKEY

JS_DESC=		JavaScript engines
DUKTAPE_DESC=		Duktape JavaScript backend
SPIDERMONKEY_DESC=	SpiderMonkey JavaScript backend

DUKTAPE_LIB_DEPENDS=	libduktape.so:lang/duktape-lib
DUKTAPE_MESON_ON=	-Djs_engine='duktape'

SPIDERMONKEY_LIB_DEPENDS=	libmozjs-102.so:lang/spidermonkey102
SPIDERMONKEY_MESON_ON=		-Djs_engine='mozjs'

MANPAGES_BUILD_DEPENDS=	docbook-sgml>0:textproc/docbook-sgml \
			docbook-xsl>0:textproc/docbook-xsl
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
