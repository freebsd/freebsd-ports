# ex:ts=8
# Ports collection makefile for:	scribus
# Date created:			Mar 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	scribus
PORTVERSION=	1.1.7
CATEGORIES=	print editors
MASTER_SITES=	http://ahnews.music.salford.ac.uk/scribus/downloads/ \
		http://web2.altmuehlnet.de/fschmid/ \
		http://scribus.planetmirror.com/ \
		http://mirrors.ntua.gr/Scribus/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A comprehensive desktop publishing program

LIB_DEPENDS=	art_lgpl_2.5:${PORTSDIR}/graphics/libart_lgpl2 \
		lcms:${PORTSDIR}/graphics/lcms \
		tiff.4:${PORTSDIR}/graphics/tiff \
		cups.2:${PORTSDIR}/print/cups-base \
		freetype.9:${PORTSDIR}/print/freetype2

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

USE_GHOSTSCRIPT_RUN=	yes

USE_BZIP2=	yes
USE_QT_VER=	3
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_PYTHON=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/scribus/libs \
		%%PREFIX%%/lib/scribus/plugins

QTCFGLIBS+=	-lm

pre-everything::
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO_MSG} ""
	@${ECHO_MSG} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO_MSG} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO_MSG} ""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g; \
		s|-O2||g' ${WRKSRC}/configure

.include <bsd.port.mk>
