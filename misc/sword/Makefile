# Created by: Willem van Engen <wvengen@stack.nl>
# $FreeBSD$

PORTNAME=	sword
PORTVERSION=	1.6.2
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.crosswire.org/pub/sword/source/v1.6/ \
		http://crosswire.org/ftpmirror/pub/sword/source/v1.6/ \
		LOCAL
MASTER_SITE_SUBDIR=	tabthorpe

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	A project framework for manipulating Bible texts

LICENSE=	GPLv2

BUILD_DEPENDS=	cppunit-config:${PORTSDIR}/devel/cppunit

MAKE_JOBS_SAFE=	yes

USE_GCC=	any
USE_GNOME=	pkgconfig
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	automake autoconf
CONFIGURE_ARGS+=	--without-conf --with-zlib
USE_LDCONFIG=	yes
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	CURL CLUCENE
CLUCENE_DESC=	Include indexing capability
OPTIONS_DEFAULT=CURL CLUCENE

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCURL}
LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	--with-curl
.else
CONFIGURE_ARGS+=	--without-curl
.endif

.if ${PORT_OPTIONS:MCLUCENE}
LIB_DEPENDS+=	clucene:${PORTSDIR}/textproc/clucene \
		icudata:${PORTSDIR}/devel/icu
CONFIGURE_ARGS+=	--with-clucene --with-icu
PLIST_SUB+=		ICU="" ICUVER="`${LOCALBASE}/bin/icu-config --version`"
.else
CONFIGURE_ARGS+=	--without-clucene --without-icu
PLIST_SUB+=		ICU="@comment "
.endif

run-autotools::	run-autotools-aclocal

post-patch:
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.am ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|:=|=|' ${WRKSRC}/Makefile.am \
		${WRKSRC}/Makefile.in ${WRKSRC}/lib/Makefile.am \
		${WRKSRC}/lib/Makefile.in
	@${REINPLACE_CMD} -e '/<curl\/types.h>/d' \
		${WRKSRC}/src/mgr/curlhttpt.cpp ${WRKSRC}/src/mgr/curlftpt.cpp

post-install:
	@${MKDIR} ${PREFIX}/share/sword/mods.d
.if !exists(${PREFIX}/etc/sword.conf)
	@(cd ${WRKSRC} && ${GMAKE} install_config)
.else
	@${ECHO_CMD} "Config file not installed since ${PREFIX}/etc/sword.conf already exists."
	@${ECHO_CMD} "Please check that DataPath points to your modules (default ${DATADIR}).";
.endif
	@${ECHO_CMD} ""
	@${CAT} ${PKGMESSAGE}

register:
	@(cd ${WRKSRC} && ${GMAKE} register)

.include <bsd.port.mk>
