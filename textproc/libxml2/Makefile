# New ports collection makefile for:	libxml2
# Date created:				28 September 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	libxml2
PORTVERSION=	2.6.5
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.6
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Xml parser library for GNOME

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--with-iconv=${LOCALBASE} \
		--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		xml2-config.1 xmllint.1 xmlcatalog.1
MAN3=		libxml.3

.if !defined(WITHOUT_PYTHON)
USE_PYTHON=	yes
PLIST_SUB+=	PYTHON:=""
CONFIGURE_ARGS+=	--with-python=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-python
PLIST_SUB+=	PYTHON:="@comment "
PKGNAMESUFFIX=	-nopython
.endif

.if defined(WITH_THREADS)
CONFIGURE_ARGS+=	--with-threads
.else
CONFIGURE_ARGS+=	--without-threads
.endif

.if defined(WITHOUT_SCHEMA)
CONFIGURE_ARGS+=	--without-schemas
.endif

.if defined(WITH_MEM_DEBUG)
CONFIGURE_ARGS+=	--with-mem-debug
.endif

.if defined(WITH_XMLLINT_HIST)
CONFIGURE_ARGS+=	--with-history
.endif

.if defined(WITH_THREAD_ALLOC)
CONFIGURE_ARGS+=	--with-thread-alloc
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "libxml2 has the following tunables:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	WITHOUT_PYTHON=yes	Turns off Python support"
	@${ECHO_MSG} "	WITH_THREADS=yes	Turns on pthread support"
	@${ECHO_MSG} "	WITHOUT_SCHEMA=yes	Turns off XML Schema support"
	@${ECHO_MSG} "	WITH_MEM_DEBUG=yes	Turns on memory debugging (DEVELOPERS ONLY!)"
	@${ECHO_MSG} "	WITH_XMLLINT_HIST=yes	Turns on history for xmllint"
	@${ECHO_MSG} "	WITH_THREAD_ALLOC=yes	Turns on per-thread memory (DEVELOPERS ONLY!)"
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/catalog.c ${WRKSRC}/xmlcatalog.c

.if !defined(WITHOUT_PYTHON)
post-install:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -l ${PYTHON_SITELIBDIR}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py -l ${PYTHON_SITELIBDIR}
.endif

.include <bsd.port.mk>
