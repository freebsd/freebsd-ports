# New ports collection makefile for:	scigraphica
# Date created:				29 August 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scigraphica
PORTVERSION=	0.6.3
CATEGORIES=	math gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://scigraphica.sourceforge.net/src/ \
		http://magnet.fsu.edu/~feiguin/scigraphica/src/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	sg-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/include/${PYTHON_VERSION}/Numeric/arrayobject.h:${PORTSDIR}/math/numpy
LIB_DEPENDS=	gtkextra.14:${PORTSDIR}/x11-toolkits/gtkextra \
		xml.5:${PORTSDIR}/textproc/libxml
RUN_DEPENDS=	${LOCALBASE}/include/${PYTHON_VERSION}/Numeric/arrayobject.h:${PORTSDIR}/math/numpy

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	yes
USE_PYTHON=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
