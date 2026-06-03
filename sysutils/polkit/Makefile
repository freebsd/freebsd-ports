PORTNAME=	polkit
DISTVERSION=	127
CATEGORIES=	sysutils gnome

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Framework for controlling access to system-wide components
WWW=		https://github.com/${GH_ACCOUNT}/${GH_PROJECT}

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libdbus-1.so:devel/dbus \
		libduktape.so:lang/duktape-lib
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dbusmock>0:devel/py-python-dbusmock@${PY_FLAVOR} \
		${LOCALBASE}/sbin/console-kit-daemon:sysutils/consolekit2

USERS=		polkitd
GROUPS=		polkitd

USES=		compiler:c++17-lang cpe dbus-testing gettext-tools gnome \
		localbase meson pathfix perl5 pkgconfig python:test shebangfix
USE_GNOME=	glib20 introspection:build
SHEBANG_FILES=	src/polkitbackend/toarray.pl \
		test/wrapper.py
USE_LDCONFIG=	yes
USE_PERL5=	build
CPE_VENDOR=	polkit_project

USE_GITHUB=	yes
GH_ACCOUNT=	polkit-org

MESON_ARGS=	-Dpam_include=system \
		-Dpam_prefix='etc/pam.d' \
		-Dpolkitd_user=${USERS} \
		-Dexamples=false \
		-Dsession_tracking=ConsoleKit \
		-Dtests=true \
		-Dintrospection=true \
		-Dgtk_doc=false \
		-Dgettext=true

OPTIONS_DEFINE=		MANPAGES

OPTIONS_SUB=		yes

MANPAGES_BUILD_DEPENDS=	docbook-sgml>0:textproc/docbook-sgml \
			docbook-xsl>0:textproc/docbook-xsl
MANPAGES_USE=		gnome=libxslt:build
MANPAGES_MESON_TRUE=	man

.ifdef ALLOW_SYSTEM_AFFECTING_TESTS
TEST_ENV+=		ALLOW_SYSTEM_AFFECTING_TESTS=1
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/|${PREFIX}/bin/|g' \
		${WRKSRC}/docs/man/pkexec.xml \
		${WRKSRC}/src/examples/org.freedesktop.policykit.examples.pkexec.policy.in
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${PREFIX}|g' \
		${WRKSRC}/docs/man/polkit.xml

post-install:
	${RM} -r ${STAGEDIR}/usr/lib/systemd
	${RM} -r ${STAGEDIR}/usr/lib/sysusers.d
	${RM} -r ${STAGEDIR}/usr/lib/tmpfiles.d

	@${MKDIR} ${STAGEDIR}/var/lib/polkit-1 \
		  ${STAGEDIR}${PREFIX}/share/polkit-1/rules.d
.for i in 10-vendor.d 20-org.d 30-site.d 50-local.d 90-mandatory.d
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/polkit-1/localauthority/${i}
	${MKDIR} ${STAGEDIR}/var/lib/polkit-1/localauthority/${i}
.endfor

.if !defined(ALLOW_SYSTEM_AFFECTING_TESTS)
post-test:
	@${ECHO_CMD}
	@${ECHO_CMD} "===> Polkit tests were skipped, because they create system users and groups"
	@${ECHO_CMD} "and are only safe to run inside a discardable jail. If that's the case, run"
	@${ECHO_CMD} "make test ALLOW_SYSTEM_AFFECTING_TESTS=yes"
	@${ECHO_CMD}
.endif

.include <bsd.port.post.mk>
