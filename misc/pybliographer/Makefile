# New ports collection makefile for:	pybliographer
# Date created:		7 December 2000
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	pybliographer
PORTVERSION=	1.0.11
PORTREVISION=	2
CATEGORIES=	misc python gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/pybliographer/1.0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI and command-line tools for editing and searching bibliographic databases

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-1.2/_gnomemodule.so:${PORTSDIR}/x11-toolkits/py-gnome \
		recode:${PORTSDIR}/converters/recode
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-1.2/_gnomemodule.so:${PORTSDIR}/x11-toolkits/py-gnome \
		recode:${PORTSDIR}/converters/recode

USE_GNOME=	glib12 gnomehack gnomeprefix
USE_PYTHON=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		Python="${PYTHON_CMD}"
CONFIGURE_ARGS=	--with-recode-prefix="${LOCALBASE}"

.include <bsd.port.pre.mk>

pre-patch:
	@${REINPLACE_CMD} 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|glib-config|glib12-config|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|\$$(datadir)/gnome/|$$(datadir)/|g ; \
		 s|\$$(datadir)/locale|$$(prefix)/share/locale|g'
.if ${PYTHON_REL} >= 230
	@${REINPLACE_CMD} 's|@DEFS@||g' ${WRKSRC}/compiled/Makefile.pre.in
.endif

post-install:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		${PREFIX}/share/gnome/${PORTNAME}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		${PREFIX}/share/gnome/${PORTNAME}

.include <bsd.port.post.mk>
