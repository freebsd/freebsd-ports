# New ports collection makefile for:	pybliographer
# Date created:		7 December 2000
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	pybliographer
PORTVERSION=	1.0.8
PORTREVISION=	1
CATEGORIES=	misc python gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/pyblio/1.0

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	GUI and command-line tools for editing and searching bibliographic databases

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-1.2/_gnomemodule.so:${PORTSDIR}/x11-toolkits/py-gnome \
		recode:${PORTSDIR}/converters/recode
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-1.2/_gnomemodule.so:${PORTSDIR}/x11-toolkits/py-gnome \
		recode:${PORTSDIR}/converters/recode

USE_GNOMENG=	yes
USE_GNOME=	glib12
USE_PYTHON=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		Python="${PYTHON_CMD}"
CONFIGURE_ARGS=	--with-recode-prefix="${LOCALBASE}"

pre-patch:
	@${REINPLACE_CMD} 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|glib-config|glib12-config|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|\$$(datadir)/gnome/|$$(datadir)/|g ; \
		 s|\$$(datadir)/locale|$$(prefix)/share/locale|g'

post-install:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		${PREFIX}/share/gnome/${PORTNAME}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		${PREFIX}/share/gnome/${PORTNAME}

.include <bsd.port.mk>
