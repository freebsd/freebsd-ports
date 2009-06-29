# Ports collection makefile for:	scribus
# Date created:			Mar 15, 2002
# Whom:				ijliao
#
# $Carpetsmoker: ports/print/scribus/Makefile,v 1.2 2007/09/24 08:06:52 carpetsmoker Exp $
# $FreeBSD$
#

PORTNAME=	scribus
PORTVERSION=	1.3.3.13
CATEGORIES=	print editors
MASTER_SITES=	SF \
		http://www.scribus.net/downloads/${PORTVERSION}/

MAINTAINER=	carpetsmoker@xs4all.nl
COMMENT=	A comprehensive desktop publishing program

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		lcms.1:${PORTSDIR}/graphics/lcms \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		cups.2:${PORTSDIR}/print/cups-base \
		freetype.9:${PORTSDIR}/print/freetype2 \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter \
		${PYTHON_SITELIBDIR}/PIL/_imaging.so:${PORTSDIR}/graphics/py-imaging

USE_BZIP2=	yes
USE_QT_VER=	3
USE_GNOME=	gnometarget libartlgpl2 libxml2
USE_GHOSTSCRIPT_RUN=	yes
USE_PYTHON=	yes
USE_PERL5_BUILD=yes
USE_LDCONFIG=	yes
USE_MOTIF=      yes
USE_CMAKE=      yes
CMAKE_USE_PTHREAD=      yes

PLIST_SUB+=     SCRIBUS_VERSION=${PORTVERSION}
MAN1=           scribus.1
MANLANG=	"" pl de
MANCOMPRESSED=	no

.include <bsd.port.mk>
