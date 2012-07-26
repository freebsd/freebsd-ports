# Ports collection makefile for:	libkate
# Date created:				Sat 19 Oct 2008
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libkate
PORTVERSION=	0.4.1
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	barbara.xxx1975@libero.it
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

OPTIONS=	DOXYGEN "Build docs with doxygen (requires TeX, QT, etc.)" off \
		HTMLDOCS "Install bundled html documentation" off \
		KATEDJ "Install KateDJ (requires wxPython - WARNING!)" off

PORTDOCS=	*

.include <bsd.port.pre.mk>

.if defined(WITH_DOXYGEN)
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
.else
CONFIGURE_ARGS+=	--disable-doc
.endif

.if defined(WITH_KATEDJ)
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
.if !defined(NOPORTDOCS)
	@${REINPLACE_CMD} -E -e "s|^(katepcdir =).*|\1 ${LOCALBASE}/libdata/pkgconfig|" \
	${WRKSRC}/Makefile.in
. if !defined(WITH_HTMLDOCS) && !defined(WITH_DOXYGEN)
.  if !defined(WITH_KATEDJ)
	@${REINPLACE_CMD} -E -e \
		's|^(install-data-am: )(install-data-local )(install-man)|\1\3|; \
		s| man/KateDJ.1||' \
	${WRKSRC}/doc/Makefile.in
.  else
	@${REINPLACE_CMD} -E -e \
		's|^(install-data-am: )(install-data-local )(install-man)|\1\3|' \
	${WRKSRC}/doc/Makefile.in
.  endif
. else
.  if !defined(WITH_KATEDJ)
	@${REINPLACE_CMD} -E -e \
		' s| man/KateDJ.1||' \
	${WRKSRC}/doc/Makefile.in
.  endif
. endif
.else
	@${REINPLACE_CMD} -E -e "s|^(katepcdir =).*|\1 ${LOCALBASE}/libdata/pkgconfig|; \
		s|^(SUBDIRS =.*) doc|\1|" \
	${WRKSRC}/Makefile.in
. if !defined(WITH_KATEDJ)
	@${REINPLACE_CMD} -E -e \
		' s| man/KateDJ.1||' \
	${WRKSRC}/doc/Makefile.in
. endif
.endif

.if !defined(WITH_KATEDJ)
	@${REINPLACE_CMD} -e \
		"s|  HAVE_PYTHON_TRUE=$$|  HAVE_PYTHON_TRUE='#'|; \
		s|  HAVE_PYTHON_FALSE=\'#\'$$|  HAVE_PYTHON_FALSE=|" \
	${WRKSRC}/configure
.endif

post-install:
.for f in ${MAN1}
	${INSTALL_MAN}  ${WRKSRC}/doc/man/${f}  ${PREFIX}/man/man1
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
. for FILE in README AUTHORS COPYING THANKS ChangeLog
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
. endfor
. if defined(WITH_HTMLDOCS)
	${CP} -RPpn ${WRKSRC}/doc/html ${DOCSDIR}/html
. endif
.endif

.include <bsd.port.post.mk>
