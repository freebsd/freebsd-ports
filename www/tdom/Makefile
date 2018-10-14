# Created by: Aldert Nooitgedagt
# $FreeBSD$

PORTNAME=	tDOM
PORTVERSION=	0.9.1
CATEGORIES=	www
MASTER_SITES=	http://tdom.org/downloads/
DISTNAME=	${PORTNAME:tl}-${PORTVERSION}
EXTRACT_SUFX=	-src.tgz

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	High performance processing of XML and HTML data with Tcl

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		tcl:tea

CONFIGURE_ARGS=	--enable-threads --disable-tdomalloc
CONFIGURE_ARGS+=--with-expat=/usr
EXTRACT_AFTER_ARGS=--exclude 'expat*/*.c' --exclude 'expat*/[a-mo-z]*.h' \
		--exclude 'domalloc*'

TEST_TARGET=	test

PLIST_SUB=	PORTVERSION=${PORTVERSION}

DOCS=		CHANGES README

OPTIONS_DEFINE=	DOCS HTML5
OPTIONS_DEFAULT=${OPTIONS_DEFINE}

HTML5_DESC=	Enable parsing of HTML5 (requires gumbo)
HTML5_LIB_DEPENDS=libgumbo.so:devel/gumbo
HTML5_CONFIGURE_ENABLE=html5
HTML5_CFLAGS=	-I${LOCALBASE}/include
HTML5_USES=	pkgconfig
MAKE_ARGS+=	RANLIB_STUB=:

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}/html/

.include <bsd.port.mk>
