# ex:ts=8
# Ports collection makefile for:	scribus
# Date created:			Mar 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	scribus
PORTVERSION=	1.2.2.1
CATEGORIES=	print editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.scribus.org.uk/downloads/${PORTVERSION}/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A comprehensive desktop publishing program

LIB_DEPENDS=	lcms.1:${PORTSDIR}/graphics/lcms \
		tiff.4:${PORTSDIR}/graphics/tiff \
		cups.2:${PORTSDIR}/print/cups-base \
		freetype.9:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

USE_BZIP2=	yes
USE_QT_VER=	3
USE_GNOME=	gnometarget libartlgpl2 libxml2
USE_GHOSTSCRIPT_RUN=	yes
USE_PYTHON=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_ARGS=	--x-libraries=${X11BASE}/lib --x-includes=${X11BASE}/include

MAN1=		scribus.1
MANLANG=	"" pl

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
CXXFLAGS+=	-fpermissive
.endif

pre-everything::
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO_MSG} ""
	@${ECHO_MSG} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO_MSG} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO_MSG} ""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g; \
		 s|-O2 ||g ; \
		 s|="-lc"|=""|g ; \
		 s|2\.3|${PYTHON_VERSION:S/^python//}|g ; \
		 s|python2_3|${PYTHON_VERSION:S/./_/}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/\/share\/pixmaps\//s|^|#|g' \
		${WRKSRC}/scribus/icons/Makefile.in

.include <bsd.port.post.mk>
