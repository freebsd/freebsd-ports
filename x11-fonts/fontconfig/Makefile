PORTNAME=	fontconfig
DISTVERSION=	2.17.1
PORTEPOCH=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	https://gitlab.freedesktop.org/api/v4/projects/890/packages/generic/${PORTNAME}/${DISTVERSION}/

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	XML-based font configuration API for X Windows
WWW=		https://www.freedesktop.org/wiki/Software/fontconfig/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libexpat.so:textproc/expat2

USES=		cpe gperf meson pkgconfig python:build shebangfix tar:xz \
		trigger
CPE_VENDOR=	fontconfig_project
USE_LDCONFIG=	yes

SHEBANG_FILES=	conf.d/link_confs.py \
		conf.d/write-35-lang-normalize-conf.py \
		fc-case/fc-case.py \
		fc-lang/fc-lang.py \
		src/cutout.py \
		src/makealias.py \
		test/run-test-map.sh \
		test/run-test.sh

TEST_TARGET=	test

SUB_FILES=	pkg-message
SUB_LIST=	LOCALBASE=${LOCALBASE}

# To avoid circular dependency rebuild of docs (including manpages) needs to be
# disabled as they depend on textproc/docbook-utils which requires fontconfig
MESON_ARGS=	-Dadditional-fonts-dirs=${LOCALBASE}/lib/X11/fonts \
		-Dcache-build=disabled \
		-Dcache-dir=/var/db/fontconfig \
		-Ddefault_library=both \
		-Ddefault-fonts-dirs=${PREFIX}/share/fonts \
		-Ddoc=disabled \
		-Dtemplate-dir=${LOCALBASE}/etc/fonts/conf.avail \
		-Dxml-dir=${LOCALBASE}/etc/fonts

PLIST_SUB=	PREFERRED_HINTING=${PREFERRED_HINTING}
PORTDOCS=	fontconfig-user.html fontconfig-user.pdf fontconfig-user.txt

OPTIONS_DEFINE=	DOCS NLS BITMAPS TEST
OPTIONS_DEFAULT=BITMAPS HINTING_SLIGHT
OPTIONS_SUB=	yes

OPTIONS_SINGLE=	HINTING
.for opt in NONE SLIGHT MEDIUM FULL
OPTIONS_SINGLE_HINTING+=	HINTING_${opt}
HINTING_${opt}_DESC=	${opt:tl}
HINTING_${opt}_VARS=	PREFERRED_HINTING=${opt:tl}
HINTING_${opt}_MESON_ON=	-Ddefault-hinting=${opt:tl}
.endfor

BITMAPS_DESC=	Enable bitmap fonts by default
HINTING_DESC=	Preferred pixel hinting configuration

BITMAPS_MESON_YES=	bitmap-conf

NLS_USES=		gettext-runtime gettext-tools
NLS_MESON_ENABLED=	nls

TEST_TEST_DEPENDS=	bash:shells/bash
TEST_MESON_ENABLED=	tests
TESTING_UNSAFE=		Requires network access for fetching fonts

post-install:
	${INSTALL_MAN} ${WRKSRC}/fc-*/*.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/*.3 ${STAGEDIR}${PREFIX}/share/man/man3
	${INSTALL_MAN} ${WRKSRC}/doc/*.5 ${STAGEDIR}${PREFIX}/share/man/man5
	${MV} ${STAGEDIR}${PREFIX}/etc/fonts/fonts.conf ${STAGEDIR}${PREFIX}/etc/fonts/fonts.conf.sample
	@${MKDIR} ${STAGEDIR}/var/db/fontconfig

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
