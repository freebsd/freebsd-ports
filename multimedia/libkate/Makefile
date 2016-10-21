# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libkate
PORTVERSION=	0.4.1
PORTREVISION=	6
CATEGORIES=	multimedia
MASTER_SITES=	http://downloads.xiph.org/releases/kate/

MAINTAINER=	bar@FreeBSD.org
COMMENT=	Codec for karaoke and text encapsulation for Ogg

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libogg.so:audio/libogg \
		libpng.so:graphics/png

GNU_CONFIGURE=	yes
USES=		pathfix pkgconfig gmake libtool
USE_LDCONFIG=	yes

CFLAGS+=	"-I${LOCALBASE}/include"

MANPAGE=	katalyzer.1 kateenc.1 katedec.1
OPTIONS_DEFINE=	DOXYGEN HTMLDOCS KATEDJ DOCS

HTMLDOCS_DESC=	Install bundled html documentation
KATEDJ_DESC=	Install KateDJ (Huge dependencies list)

PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOXYGEN} && ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	doxygen:devel/doxygen
.else
CONFIGURE_ARGS+=	--disable-doc
.endif

.if ${PORT_OPTIONS:MKATEDJ}
RUN_DEPENDS=	${LOCALBASE}/bin/oggz:audio/liboggz
USES+=		python
USE_WX=		2.8
WX_UNICODE=	yes
WX_COMPS=	wx contrib python:lib
MANPAGE+=	KateDJ.1
PLIST_SUB+=	KATEDJ=""
.else
PLIST_SUB+=	KATEDJ="@comment "
.endif

post-patch:
.if ! ${PORT_OPTIONS:MKATEDJ}
	@${REINPLACE_CMD} -e \
		"s|  HAVE_PYTHON_TRUE=$$|  HAVE_PYTHON_TRUE='#'|; \
			s|  HAVE_PYTHON_FALSE=\'#\'$$|  HAVE_PYTHON_FALSE=|" \
		${WRKSRC}/configure
.endif

	@${REINPLACE_CMD} -E -e \
		"s|^(install-data-am: ).*|\1|" \
		${WRKSRC}/doc/Makefile.in

.if ! ${PORT_OPTIONS:MDOXYGEN} || ! ${PORT_OPTIONS:MDOCS}
	@${TOUCH} ${WRKSRC}/doc/.doc-dummy-target
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so
.for f in ${MANPAGE}
	${INSTALL_MAN} ${WRKSRC}/doc/man/${f} ${STAGEDIR}${PREFIX}/man/man1
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in README AUTHORS COPYING THANKS ChangeLog
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor
.if ${PORT_OPTIONS:MHTMLDOCS} || ${PORT_OPTIONS:MDOXYGEN}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})
. endif

.include <bsd.port.mk>
