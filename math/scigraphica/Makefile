# New ports collection makefile for:	scigraphica
# Date created:				29 August 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scigraphica
PORTVERSION=	0.7.1
CATEGORIES=	math gnome
MASTER_SITES=	http://scigraphica.sourceforge.net/src/ \
		${MASTER_SITE_SOURCEFORGE} \
		http://magnet.fsu.edu/~feiguin/scigraphica/src/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	sg-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	${PYNUMERIC}
LIB_DEPENDS=	gtkextra.16:${PORTSDIR}/x11-toolkits/gtkextra
RUN_DEPENDS=	${PYNUMERIC} \
		${PYTHON_SITELIBDIR}/_gtkmodule.so:${PORTSDIR}/x11-toolkits/py-gtk

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	yes
USE_PYTHON=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${PYTHON_VERSION} == "python2.0" || ${PYTHON_VERSION} == "python2.1"
PYNUMERIC=      ${LOCALBASE}/include/${PYTHON_VERSION}/Numeric/arrayobject.h:${PORTSDIR}/math/py-numeric
.else
PYNUMERIC=      ${LOCALBASE}/include/${PYTHON_VERSION}/Numeric/arrayobject.h:${PORTSDIR}/math/py-numeric17
.endif

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

post-install:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/share/gnome/scigraphica
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/share/gnome/scigraphica

.include <bsd.port.post.mk>
