# Ports collection makefile for:	scribus
# Date created:			Mar 15, 2002
# Whom:				ijliao
#
# $Carpetsmoker: ports/print/scribus/Makefile,v 1.2 2007/09/24 08:06:52 carpetsmoker Exp $
# $FreeBSD$
#

PORTNAME=	scribus
PORTVERSION=	1.3.3.11
PORTREVISION=	2
CATEGORIES=	print editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.scribus.net/downloads/${PORTVERSION}/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	carpetsmoker@xs4all.nl
COMMENT=	A comprehensive desktop publishing program

LIB_DEPENDS=	lcms.1:${PORTSDIR}/graphics/lcms \
		tiff.4:${PORTSDIR}/graphics/tiff \
		cups.2:${PORTSDIR}/print/cups-base \
		freetype.9:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter \
		${PYTHON_SITELIBDIR}/PIL/_imaging.so:${PORTSDIR}/graphics/py-imaging

USE_BZIP2=	yes
USE_QT_VER=	3
USE_GNOME=	gnometarget libartlgpl2 libxml2
USE_GHOSTSCRIPT_RUN=	yes
USE_PYTHON=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
CONFIGURE_ARGS=	--enable-scripter2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PLIST_SUB+=	SCRIBUS_VERSION=${PORTVERSION}
MAN1=		scribus.1
MANCOMPRESSED=	no
MANLANG=	"" pl pl_PL.UTF-8 pl_PL.ISO8859-2 de de_DE.UTF-8 \
		de_DE.ISO8859-1 de_DE.ISO8859-15

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g; \
		s|-O2 ||g ; \
		s|="-lc"|=""|g ; \
		s|python2\.3|python${PYTHON_VERSION:S/^python//}|g ; \
		s|Python 2\.3|Python ${PYTHON_VERSION:S/^python//}|g ; \
		s|python2_3|${PYTHON_VERSION:S/./_/}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/\/share\/pixmaps\//s|^|#|g' \
		${WRKSRC}/scribus/icons/Makefile.in
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' \
	    ${WRKSRC}/configure

.include <bsd.port.post.mk>
