# New ports collection makefile for:	manslide
# Date created:		Mer 28 Feb 2007 23:25:17 CET
# Whom:                	Diego Depaoli <trebestie@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	manslide
DISTVERSION=	2.0.1
CATEGORIES=	multimedia kde
MASTER_SITES=	http://csgib36.ifrance.com/Manslide/

MAINTAINER=	trebestie@gmail.com
COMMENT=	Utility to simply create your own slideshow

RUN_DEPENDS=	sox>=13.0:${PORTSDIR}/audio/sox \
		mencoder:${PORTSDIR}/multimedia/mencoder \
		mplayer:${PORTSDIR}/multimedia/mplayer \
		mjpegtools>1.8.9:${PORTSDIR}/multimedia/mjpegtools \
		ImageMagick>=6.3:${PORTSDIR}/graphics/ImageMagick \
		smilutils>=0.3.2:${PORTSDIR}/multimedia/smilutils \
		netpbm-devel>=10.31:${PORTSDIR}/graphics/netpbm-devel \
		vorbis-tools>=1.1.1:${PORTSDIR}/audio/vorbis-tools

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build gui_build corelib_build rcc_build \
		moc_build uic_build opengl imageformats_run \
		svg_run xml_run inputmethods_run

MANSLIDEDIR=	${PREFIX}/share/manslide

MAKE_ENV?=	QTDIR=${QT_PREFIX}
LANGUAGE_FILES=	_ca _de _en _pl _it _hu _ru _nl _ro _sp _fi
EXTENSIONS=	png jpg PNG

DESKTOP_ENTRIES=	"Manslide" \
  			"Create your slideshow" \
  			"manslide.png" \
			"Manslide" \
       			"Application;AudioVideo;" \
			false

post-extract:
# bash it isn't the FreeBSD's default shell
	@${REINPLACE_CMD} -e 's|bash|sh|g' ${WRKSRC}/mainfrm.cpp

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} -spec ${QMAKESPEC}

pre-install:
	${MKDIR} ${MANSLIDEDIR}/BIB_ManSlide
	${MKDIR} ${MANSLIDEDIR}/BIB_ManSlide/Eff_sup
	${MKDIR} ${MANSLIDEDIR}/BIB_ManSlide/Luma
	${MKDIR} ${MANSLIDEDIR}/Interface
	${INSTALL_PROGRAM} ${WRKSRC}/Manslide ${MANSLIDEDIR}/

do-install:
.for extensions in ${EXTENSIONS}
	${INSTALL_DATA} ${WRKSRC}/Interface/*${extensions} ${MANSLIDEDIR}/Interface/
.endfor
	${CP} -R ${WRKSRC}/BIB_ManSlide ${MANSLIDEDIR}
	${INSTALL_DATA} ${WRKSRC}/icone.png ${PREFIX}/share/pixmaps/manslide.png

.for lang in ${LANGUAGE_FILES}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}${lang}.qm ${MANSLIDEDIR}
.endfor

	${LN} -fs ${MANSLIDEDIR}/Manslide ${PREFIX}/bin/

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile
.endif

.include <bsd.port.post.mk>
