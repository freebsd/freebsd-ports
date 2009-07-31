# New ports collection makefile for:	scigraphica
# Date created:				29 August 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scigraphica
PORTVERSION=	0.8.0
PORTREVISION=	8
CATEGORIES=	math gnome
MASTER_SITES=	http://scigraphica.sourceforge.net/src/ \
		SF \
		http://magnet.fsu.edu/~feiguin/scigraphica/src/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A scientific application for data analysis and technical graphics

BUILD_DEPENDS=	${PYNUMERIC}
LIB_DEPENDS=	gtkextra.17:${PORTSDIR}/x11-toolkits/gtkextra
RUN_DEPENDS=	${PYNUMERIC} \
		${PYTHON_SITELIBDIR}/gtk-1.2/_gtkmodule.so:${PORTSDIR}/x11-toolkits/py-gtk

USE_PERL5_BUILD=yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gtkhtml
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}"

.include <bsd.port.pre.mk>

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

post-install:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/share/scigraphica
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/share/scigraphica

.include <bsd.port.post.mk>
