# New ports collection makefile for:	pybliographer
# Date created:		7 December 2000
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	pybliographer
PORTVERSION=	1.0.8
CATEGORIES=	misc python gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/pyblio/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/_gnomemodule.so:${PORTSDIR}/x11-toolkits/py-gnome \
		recode:${PORTSDIR}/converters/recode
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_gnomemodule.so:${PORTSDIR}/x11-toolkits/py-gnome \
		recode:${PORTSDIR}/converters/recode

USE_GLIB=	yes
USE_PYTHON=	yes
USE_GNOME=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		Python="${PYTHON_CMD}"
CONFIGURE_ARGS=	--with-recode-prefix="${LOCALBASE}"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

post-install:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		${PREFIX}/share/gnome/${PORTNAME}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		${PREFIX}/share/gnome/${PORTNAME}

.include <bsd.port.mk>
