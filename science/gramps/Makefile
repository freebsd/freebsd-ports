# New ports collection makefile for:	gramps
# Date created:		2003-12-25
# Whom:			Andreas Fehlner <fehlner@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	gramps
PORTVERSION=	0.98.0
CATEGORIES=	science gnome python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gramps

MAINTAINER=	fehlner@gmx.de
COMMENT=	A GTK/GNOME-based genealogy program written in Python

BUILD_DEPENDS=	${PYTHON_LIBDIR}/site-packages/_xmlplus/__init__.py:${PORTSDIR}/textproc/py-xml \
		${PYTHON_SITELIBDIR}/gtk-2.0/gnome/__init__.py:${PORTSDIR}/x11-toolkits/py-gnome2

USE_X_PREFIX=	yes
USE_PYTHON=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

MAN1=		gramps.1

post-patch:
	@${REINPLACE_CMD} -e 's|{prefix}/share|{prefix}/share/gnome|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|gnome/help|help|' ${WRKSRC}/doc/gramps-manual/C/Makefile.in
	@${REINPLACE_CMD} -e 's|share/gramps|share/gnome/gramps|g' ${WRKSRC}/src/gramps_main.py

.include <bsd.port.mk>
