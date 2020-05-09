# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fontconfig
PORTVERSION=	2.13.92
PORTREVISION?=	2
PORTEPOCH?=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	https://www.freedesktop.org/software/fontconfig/release/

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	XML-based font configuration API for X Windows

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gperf tar:xz

.if !defined(REFERENCE_PORT)

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libexpat.so:textproc/expat2

USES+=		cpe gmake libtool pathfix pkgconfig
CPE_VENDOR=	fontconfig_project
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-configdir=${PREFIX}/etc/fonts/conf.d \
		--with-templatedir=${PREFIX}/etc/fonts/conf.avail \
		--with-xmldir=${PREFIX}/etc/fonts \
		--with-expat-includes=${LOCALBASE}/include \
		--with-expat-lib=${LOCALBASE}/lib \
		--with-default-hinting=${PREFERRED_HINTING} \
		--with-default-fonts=${PREFIX}/share/fonts \
		--with-add-fonts=${LOCALBASE}/lib/X11/fonts \
		--with-cache-dir=/var/db/fontconfig \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig \
		--disable-docs

# D6155: static linked library linking added to support statically linked
# 	 applications, e.g. x11/xforward static option
CONFIGURE_ARGS+=	--enable-static

PKGINSTALL=	${WRKDIR}/pkg-install
INSTALL_TARGET=install-strip

PLIST_SUB=	PREFERRED_HINTING=${PREFERRED_HINTING}
PORTDOCS=	fontconfig-user.html fontconfig-user.pdf fontconfig-user.txt

OPTIONS_DEFINE=	DOCS NLS NO_BITMAPS
OPTIONS_DEFAULT=HINTING_SLIGHT
OPTIONS_SUB=	yes

NO_BITMAPS_DESC=	Reject bitmap fonts by default

OPTIONS_SINGLE=	HINTING
HINTING_DESC=	Preferred pixel hinting configuration
.for opt in NONE SLIGHT MEDIUM FULL
OPTIONS_SINGLE_HINTING+=	HINTING_${opt}
HINTING_${opt}_DESC=	${opt:tl}
HINTING_${opt}_VARS=	PREFERRED_HINTING=${opt:tl}
.endfor

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch-NO_BITMAPS-on:
	@${REINPLACE_CMD} -i '.bitmaps.bak' -e \
		'/^CONF_LINKS =/s|$$|\${.newline}	70-no-bitmaps.conf \\|' \
		${WRKSRC}/conf.d/Makefile.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/fc-*/*.1 \
		${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/*.5 \
		${STAGEDIR}${PREFIX}/man/man5
	${INSTALL_DATA} ${WRKSRC}/fonts.conf \
		${STAGEDIR}${PREFIX}/etc/fonts/fonts.conf.sample
	@${SED} -e 's|%%PREFIX%%|${PREFIX}| ; \
		s|%%LOCALBASE%%|${LOCALBASE}|' < ${FILESDIR}/pkg-install.in \
		> ${PKGINSTALL}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

.endif
