# New ports collection makefile for:	slideshow
# Date created:			26 November 2002
# Whom:				Stefan Farfeleder <e0026813@stud3.tuwien.ac.at>
#
# $FreeBSD$
#

PORTNAME=	slideshow
PORTVERSION=	0.8.0.p4
CATEGORIES=	multimedia
MASTER_SITES=	http://savannah.nongnu.org/download/${PORTNAME}/${PORTNAME}.pkg/${PORTVERSION:S/.p/-pre/}/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.p/-pre/}

MAINTAINER=	e0026813@stud3.tuwien.ac.at

LIB_DEPENDS=	SDL_ttf.3:${PORTSDIR}/graphics/sdl_ttf \
		SDL_image.10:${PORTSDIR}/graphics/sdl_image \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		smpeg.1:${PORTSDIR}/graphics/smpeg

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
USE_PYTHON=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS+=	--disable-gtk-gui
CONFIGURE_ENV+=	SDL_CONFIG="${SDL_CONFIG}" LDFLAGS="-lstdc++"

.include <bsd.port.pre.mk>

# The default resolution is 640x480
.if defined(WITH_RES_1024)
CONFIGURE_ARGS+=	--with-res=1024
.elif defined(WITH_RES_800)
CONFIGURE_ARGS+=	--with-res=800
.endif

pre-patch:
	@${REINPLACE_CMD} -e '/SUBDIRS =/s/doc//' ${WRKSRC}/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/SUBDIRS =/s/examples//' ${WRKSRC}/Makefile.in
.endif

post-configure:
	@${REINPLACE_CMD} -e "/^pythondir/s|= .*|= ${PYTHONPREFIX_SITELIBDIR}|"\
		${WRKSRC}/src/Makefile

do-install:
	@(cd ${WRKSRC}/src; ${MAKE} install)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
# Don't install Simple.py, it is broken
.for file in AutoSlide.py Backgrounds.py Simple.xml Stages.py Text.py Video.py \
	Xml.py slideshow.dtd speedfull.jpg standard.ttf
	${INSTALL_MAN} ${WRKSRC}/examples/${file} ${EXAMPLESDIR}
.endfor
.endif

post-install:
	@${STRIP_CMD} ${PREFIX}/lib/libslideshow.so.0
#	@${STRIP_CMD} ${PYTHONPREFIX_SITELIBDIR}/_slideshow.so
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
