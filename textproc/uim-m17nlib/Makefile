# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	2
.if defined(WITHOUT_X11)
PKGNAMESUFFIX=	-m17nlib-nox11
.else
PKGNAMESUFFIX=	-m17nlib
.endif

COMMENT=	Uim plugin using m17n library input method

BUILD_DEPENDS=	m17n-db:devel/m17n-db
LIB_DEPENDS=	libm17n.so:devel/m17n-lib \
		libuim.so:textproc/uim
RUN_DEPENDS=	m17n-db:devel/m17n-db

.if !defined(WITHOUT_M17NCONTRIB)
RUN_DEPENDS+=	${LOCALBASE}/share/m17n/icons/as-phonetic.png:devel/m17n-db
.endif

MASTERDIR=	${.CURDIR}/../../textproc/uim
PKGDIR=		${.CURDIR}
CONFIGURE_ARGS=	--with-m17nlib

UIM_SLAVE=	yes

EXTRA_PATCHES=	${PATCHDIR}/extra-patch-uim_Makefile.in

do-build:
	(cd ${WRKSRC}/uim && ${MAKE_CMD} libuim-m17nlib.la)

do-install:
	(cd ${WRKSRC}/uim && \
	${MAKE_CMD} DESTDIR=${STAGEDIR} uim_plugin_LTLIBRARIES=libuim-m17nlib.la install-uim_pluginLTLIBRARIES && \
	${MKDIR} ${STAGEDIR}${PREFIX}/share/uim/pixmaps && \
	DESTDIR="${STAGEDIR}" ${SH} ../pixmaps/uim-m17nlib-relink-icons)

post-install:
	@${FIND} ${LOCALBASE}/share/m17n/icons/ -name '*.png' -execdir ${ECHO} share/uim/pixmaps/m17n-{} \; >>${TMPPLIST}

.include "${MASTERDIR}/Makefile"
