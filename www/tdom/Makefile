PORTNAME=	tDOM
DISTVERSION=	0.9.4
CATEGORIES=	www
MASTER_SITES=	http://tdom.org/downloads/
DISTNAME=	${PORTNAME:tl}-${PORTVERSION}-src

MAINTAINER=	ports@virtual-estates.net
COMMENT=	High performance processing of XML and HTML data with Tcl
WWW=		http://www.tdom.org/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		tcl:tea

CONFIGURE_ARGS=	--enable-threads --disable-tdomalloc
EXTRACT_AFTER_ARGS=	--exclude 'expat*/*.c' --exclude 'expat*/[a-mo-z]*.h' \
			--exclude 'domalloc*' --exclude win

MAKE_ARGS+=	RANLIB_STUB=:
TEST_TARGET=	test

PLIST_SUB=	PORTVERSION=${PORTVERSION}

DOCS=		CHANGES README.md

OPTIONS_DEFINE=		DOCS HTML5
OPTIONS_DEFAULT=	${OPTIONS_DEFINE} EBASE
OPTIONS_SINGLE=		EXPAT
OPTIONS_SINGLE_EXPAT=	EBASE EPORTS

EBASE_DESC=	Use Expat from base
EPORTS_DESC=	Use Expat from ports
HTML5_DESC=	Enable parsing of HTML5 (requires gumbo)

EBASE_CONFIGURE_ON=	--with-expat=/usr
EPORTS_LIB_DEPENDS=	libexpat.so:textproc/expat2
EPORTS_CONFIGURE_ON=	--with-expat=${LOCALBASE}
HTML5_LIB_DEPENDS=	libgumbo.so:devel/gumbo
HTML5_USES=		pkgconfig
HTML5_CONFIGURE_ENABLE=	html5
HTML5_CFLAGS=		-I${LOCALBASE}/include

post-patch-EBASE-on:
	${REINPLACE_CMD} 's|\([</]\)expat\.h|\1bsdxml.h|g' \
	    ${WRKSRC}/configure \
	    ${WRKSRC}/generic/dom.h \
	    ${WRKSRC}/generic/tdom.h \
	    ${WRKSRC}/generic/tclexpat.h
	${REINPLACE_CMD} 's|-lexpat|-lbsdxml|' ${WRKSRC}/configure
	${REINPLACE_CMD} '553s|$$|knownBug} {|' ${WRKSRC}/tests/dom.test

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}/html/

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/tdom0.9.4/libtdom0.9.4.so

.include <bsd.port.mk>
