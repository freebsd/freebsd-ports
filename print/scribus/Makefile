# ex:ts=8
# Ports collection makefile for:	scribus
# Date created:			Mar 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	scribus
PORTVERSION=	1.2
CATEGORIES=	print editors
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://scribus.planetmirror.com/ \
		http://www.scribus.org.uk/downloads/${PORTVERSION}/ \
		http://docs.scribus.net/releases/${PORTVERSION}/ \
		http://web2.altmuehlnet.de/fschmid/ \
		http://ahnews.music.salford.ac.uk/scribus/downloads/ \
		http://mirrors.ntua.gr/Scribus/
MASTER_SITE_SUBDIR=	apps/office

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A comprehensive desktop publishing program

BROKEN=		"Broken pkg-plist"

LIB_DEPENDS=	lcms.1:${PORTSDIR}/graphics/lcms \
		tiff.4:${PORTSDIR}/graphics/tiff \
		cups.2:${PORTSDIR}/print/cups-base \
		freetype.9:${PORTSDIR}/print/freetype2

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

USE_BZIP2=	yes
USE_QT_VER=	3
USE_GNOME=	libartlgpl2 gnometarget
USE_GHOSTSCRIPT_RUN=	yes
USE_PYTHON=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/scribus/libs \
		%%PREFIX%%/lib/scribus/plugins

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
