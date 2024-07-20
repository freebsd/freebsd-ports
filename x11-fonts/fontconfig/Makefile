PORTNAME=	fontconfig
DISTVERSION=	2.15.0
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	https://www.freedesktop.org/software/${PORTNAME}/release/

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
		fc-lang/fc-lang.py

TEST_TARGET=	test

SUB_FILES=	pkg-message
SUB_LIST=	LOCALBASE=${LOCALBASE}

# To avoid circular dependency rebuild of docs (including manpages) needs to be
# disabled as they depend on textproc/docbook-utils which requires fontconfig
MESON_ARGS=	-Ddefault_library=both -Ddoc=disabled -Dcache-build=disabled \
		-Ddefault-fonts-dirs=${PREFIX}/share/fonts \
		-Dadditional-fonts-dirs=${LOCALBASE}/lib/X11/fonts \
		-Dlocalstatedir=/var \
		-Dcache-dir=/var/db/fontconfig \
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

NLS_USES=		gettext-tools
NLS_MESON_ENABLED=	nls

TEST_MESON_ENABLED=	tests

post-install:
	${INSTALL_MAN} ${WRKSRC}/fc-*/*.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/*.3 ${STAGEDIR}${PREFIX}/share/man/man3
	${INSTALL_MAN} ${WRKSRC}/doc/*.5 ${STAGEDIR}${PREFIX}/share/man/man5
	${MV} ${STAGEDIR}${PREFIX}/etc/fonts/fonts.conf ${STAGEDIR}${PREFIX}/etc/fonts/fonts.conf.sample
	@${MKDIR} ${STAGEDIR}/var/db/fontconfig

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}

post-install-BITMAPS-off:
	${RLN} ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail/70-no-bitmaps.conf ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/70-no-bitmaps.conf

post-install-BITMAPS-on:
	${RM} ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/70-no-bitmaps.conf
	${RLN} ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail/70-yes-bitmaps.conf ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/70-yes-bitmaps.conf

.include <bsd.port.mk>
