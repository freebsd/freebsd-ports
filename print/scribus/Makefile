# ex:ts=8
# Ports collection makefile for:	scribus
# Date created:			Mar 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	scribus
PORTVERSION=	1.3.3.1
CATEGORIES=	print editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.scribus.net/downloads/${PORTVERSION}/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	rainer.alves@gmail.com
COMMENT=	A comprehensive desktop publishing program

LIB_DEPENDS=	lcms.1:${PORTSDIR}/graphics/lcms \
		tiff.4:${PORTSDIR}/graphics/tiff \
		cups.2:${PORTSDIR}/print/cups-base \
		freetype.9:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter \
		${PYTHON_SITELIBDIR}/PIL/_imaging.so:${PORTSDIR}/graphics/py-imaging

USE_BZIP2=	yes
USE_QT_VER=	3
USE_GCC=	3.3+
USE_GNOME=	gnometarget libartlgpl2 libxml2
USE_GHOSTSCRIPT_RUN=	yes
USE_PYTHON=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--x-libraries=${X11BASE}/lib --x-includes=${X11BASE}/include

PLIST_SUB+=	SCRIBUS_VERSION=${PORTVERSION}
MAN1=		scribus.1
MANLANG=	"" pl

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
CXXFLAGS+=	-fpermissive
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g; \
		s|-O2 ||g ; \
		s|="-lc"|=""|g ; \
		s|python2\.3|python${PYTHON_VERSION:S/^python//}|g ; \
		s|Python 2\.3|Python ${PYTHON_VERSION:S/^python//}|g ; \
		s|python2_3|${PYTHON_VERSION:S/./_/}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/\/share\/pixmaps\//s|^|#|g' \
		${WRKSRC}/scribus/icons/Makefile.in

.include <bsd.port.post.mk>
