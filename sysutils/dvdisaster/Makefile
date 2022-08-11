PORTNAME=	dvdisaster
PORTVERSION=	0.79.5
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ml1.org.uk/distfiles/ \
		http://www.ancientgeek.org.uk/distfiles/

MAINTAINER=	bob@eager.cx
COMMENT=	Optical disc error correction data and recovery tool

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		gmake gnome pkgconfig
USE_GCC=	yes
USE_GNOME=	gdkpixbuf2 gtk20 cairo

CFLAGS+=	-Wno-stringop-overflow
MAKEFILE=	GNUmakefile
HAS_CONFIGURE=	yes
CONFIGURE_LOG=	configure.log
CONFIGURE_ARGS=	--docsubdir="/" \
		--localedir=${PREFIX}/share/locale \
		--buildroot=${STAGEDIR}
MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	*
SUB_FILES=	pkg-message DEVICES.md DEVICES.html

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

DOCS_CONFIGURE_ON=	--docdir=${DOCSDIR}
NLS_USES=	gettext
NLS_CONFIGURE_OFF=	-with-nls=no

post-patch:
	${REINPLACE_CMD} -e '/dvdisaster uninstaller/,+19 d' \
			${WRKSRC}/GNUmakefile.template

post-patch-DOCS-off:
	${REINPLACE_CMD} -e 's|THESE_ARE_THE_DEVEL_SOURCES;|GNUmakefile;|; \
		/install -d $$(BUILDROOT)$$(DOCSUBDIR)/,+7 d' \
			${WRKSRC}/GNUmakefile.template

post-patch-NLS-off:
	${REINPLACE_CMD} -Ee 's|(PO_LOCALES)|#\1|; \
		s|install -m 644 CREDITS\*|install -m 644 CREDITS\.en|' \
			${WRKSRC}/GNUmakefile.template

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/contrib/dvdisaster48.png ${STAGEDIR}${PREFIX}/share/pixmaps/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/contrib/dvdisaster.desktop ${STAGEDIR}${PREFIX}/share/applications/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-DOCS-on:
	${INSTALL_MAN} ${WRKDIR}/DEVICES.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKDIR}/DEVICES.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
