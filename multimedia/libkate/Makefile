# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libkate
PORTVERSION=	0.4.1
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	bar@FreeBSD.org
COMMENT=	Codec for karaoke and text encapsulation for Ogg

LICENSE=	BSD

LIB_DEPENDS=	ogg:${PORTSDIR}/audio/libogg \
		png15:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_PKGCONFIG=	yes

CFLAGS+=	"-I${LOCALBASE}/include"

MAN1=		katalyzer.1 kateenc.1 katedec.1

OPTIONS_DEFINE=		DOXYGEN HTMLDOCS KATEDJ

HTMLDOCS_DESC=	Install bundled html documentation
KATEDJ_DESC=	Install KateDJ (Huge dependencies list)

PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOXYGEN} && ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
.else
CONFIGURE_ARGS+=	--disable-doc
.endif

.if ${PORT_OPTIONS:MKATEDJ}
RUN_DEPENDS=	${LOCALBASE}/bin/oggz:${PORTSDIR}/audio/liboggz
USE_PYTHON=	yes
.include "${PORTSDIR}/Mk/bsd.python.mk"
USE_WX=		2.8
WX_COMPS=	wx contrib python:lib
MAN1+=		KateDJ.1
PLIST_SUB+=	KATEDJ=""
.else
PLIST_SUB+=	KATEDJ="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -E -e \
		"s|^(katepcdir =).*|\1 ${PREFIX}/libdata/pkgconfig|" \
		${WRKSRC}/Makefile.in

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
.for f in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/doc/man/${f} ${PREFIX}/man/man1
.endfor
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
. for FILE in README AUTHORS COPYING THANKS ChangeLog
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
. endfor
. if ${PORT_OPTIONS:MHTMLDOCS} || ${PORT_OPTIONS:MDOXYGEN}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${DOCSDIR})
. endif
.endif

.include <bsd.port.mk>
