PORTNAME=	chemtool
PORTVERSION=	1.7.20050716
PORTREVISION=	11
CATEGORIES=	science
MASTER_SITES=	http://ruby.chemie.uni-freiburg.de/~martin/chemtool/
PKGNAMESUFFIX=	-devel
DISTNAME=	ct17a15

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Drawing organic molecules easily and store them (developer version)

LICENSE=	GPLv2

LIB_DEPENDS=	libEMF.so:graphics/libemf \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=	fig2dev:print/fig2dev

USES=		compiler:c++11-lang gettext gmake gnome pkgconfig tar:tgz xorg
USE_GNOME=	cairo gdkpixbuf2 gtk20
USE_XORG=	x11
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-emf=yes
MAKE_ARGS+=	MAKE=${MAKE_CMD}
CFLAGS+=	-fcommon
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libEMF
LIBS+=		-L${LOCALBASE}/lib

CONFLICTS_INSTALL=	chemtool

WRKSRC=		${WRKDIR}/${PORTNAME}-1.7alpha15/

PORTEXAMPLES=	*
OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} '/^SYS_LIBRARIES =/s/$$/ -lX11/' ${WRKSRC}/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/chemtool
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cht

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
