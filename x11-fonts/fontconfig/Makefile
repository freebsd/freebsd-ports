# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>

PORTNAME=	fontconfig
DISTVERSION=	2.13.94
PORTEPOCH=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	https://www.freedesktop.org/software/fontconfig/release/

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	XML-based font configuration API for X Windows

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libexpat.so:textproc/expat2

USES=		cpe gperf meson pkgconfig python:3.6+,build shebangfix tar:xz
CPE_VENDOR=	fontconfig_project
USE_LDCONFIG=	yes

SHEBANG_FILES=	conf.d/link_confs.py \
		conf.d/write-35-lang-normalize-conf.py \
		fc-case/fc-case.py \
		fc-lang/fc-lang.py

TEST_TARGET=	test

# Custom configuration variables
FCDEFAULTFONTS=	${PREFIX}/share/fonts
FCADDFONTS=	${LOCALBASE}/lib/X11/fonts

# To avoid circular depdency docs (including manpages) needs to be disabled as
# they depend on textproc/docbook-utils which requires fontconfig
MESON_ARGS=	-Ddefault_library=both -Ddoc=disabled

PLIST_SUB=	PREFERRED_HINTING=${PREFERRED_HINTING}

OPTIONS_DEFINE=	NLS BITMAPS TEST
OPTIONS_DEFAULT=BITMAPS HINTING_SLIGHT
OPTIONS_SUB=	yes

OPTIONS_SINGLE=	HINTING
.for opt in NONE SLIGHT MEDIUM FULL
OPTIONS_SINGLE_HINTING+=	HINTING_${opt}
HINTING_${opt}_DESC=	${opt:tl}
HINTING_${opt}_VARS=	PREFERRED_HINTING=${opt:tl}
.endfor

BITMAPS_DESC=	Enable bitmap fonts by default
HINTING_DESC=	Preferred pixel hinting configuration

NLS_USES=		gettext-tools
NLS_MESON_ENABLED=	nls

TEST_MESON_ENABLED=	tests

post-patch:
	@${REINPLACE_CMD} -e 's|%%FCDEFAULTFONTS%%|${FCDEFAULTFONTS}|g' \
	    ${PATCH_WRKSRC}/meson.build
	@${REINPLACE_CMD} -e 's|%%FCADDFONTS%%|${FCADDFONTS}|g' \
	    ${PATCH_WRKSRC}/meson.build
	@${REINPLACE_CMD} -e 's|%%FCPREFERREDHINTING%%|${PREFERRED_HINTING}|g' \
	    ${PATCH_WRKSRC}/conf.d/meson.build

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/fonts/fonts.conf ${STAGEDIR}${PREFIX}/etc/fonts/fonts.conf.sample
	@${MKDIR} ${STAGEDIR}/var/db/fontconfig

post-install-BITMAPS-off:
	${RLN} ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail/70-no-bitmaps.conf ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/70-no-bitmaps.conf

post-install-BITMAPS-on:
	${RM} ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/70-no-bitmaps.conf
	${RLN} ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail/70-yes-bitmaps.conf ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/70-yes-bitmaps.conf

.include <bsd.port.mk>
