# New ports collection makefile for:	libxml2
# Date created:				28 September 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	libxml2
PORTVERSION=	2.4.28
PORTREVISION=	1
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.4
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv
RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--with-iconv=${LOCALBASE} \
		--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		xml2-config.1 xmllint.1 xmlcatalog.1
MAN3=		libxml.3

.if !defined(WITHOUT_PYTHON)
USE_PYTHON=	yes
PLIST_SUB+=	PYTHON:=""
.else
CONFIGURE_ARGS+=	--without-python
PLIST_SUB+=	PYTHON:="@comment "
PKGNAMESUFFIX=	-nopython
.endif

.if defined(WITH_SCHEMA)
CONFIGURE_ARGS+=	--with-schemas
.endif

.if defined(WITH_MEM_DEBUG)
CONFIGURE_ARGS+=	--with-mem-debug
.endif

.if defined(WITH_XMLLINT_HIST)
CONFIGURE_ARGS+=	--with-history
.endif

.if defined(WITH_THREADS)
CONFIGURE_ARGS+=	--with-threads
.endif

.if defined(WITH_THREAD_ALLOC)
CONFIGURE_ARGS+=	--with-thread-alloc
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "libxml2 has the following tunables:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "		WITHOUT_PYTHON=yes	Turns off Python support"
	@${ECHO_MSG} "		WITH_SCHEMA=yes		Turns on XML Schema support"
	@${ECHO_MSG} "		WITH_MEM_DEBUG=yes	Turns on memory debugging"
	@${ECHO_MSG} "		WITH_XMLLINT_HIST=yes	Turns on history for xmllint"
	@${ECHO_MSG} "		WITH_THREADS=yes	Turns on multi-threading support"
	@${ECHO_MSG} "		WITH_THREAD_ALLOC=yes	Turns on per-thread memory"
	@${ECHO_MSG} ""

pre-patch:
	@find ${WRKSRC} -name Makefile.in | xargs ${REINPLACE_CMD} -e \
		's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g'

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/catalog.c ${WRKSRC}/xmlcatalog.c

.include <bsd.port.mk>
