# New ports collection makefile for:	gramps
# Date created:		2003-12-25
# Whom:			Andreas Fehlner <fehlner@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	gramps
PORTVERSION=	2.0.5
CATEGORIES=	science gnome python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gramps

MAINTAINER=	stefan.tell@crashmail.de
COMMENT=	A GTK/GNOME-based genealogy program written in Python

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_bsddb.so:${PORTSDIR}/databases/py-bsddb \
		${PYTHON_LIBDIR}/site-packages/_xmlplus/__init__.py:${PORTSDIR}/textproc/py-xml

USE_X_PREFIX=	yes
USE_PYTHON=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix pygnome2 desktopfileutils
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
INSTALLS_OMF=	yes

MAN1=		gramps.1
GCONF_SCHEMAS=	gramps.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|/@PACKAGE@/gnome||' \
		${WRKSRC}/doc/gramps-manual/C/Makefile.in
	@${REINPLACE_CMD} -e 's|share/gramps|share/gnome|' \
		${WRKSRC}/src/gramps_main.py
	@${REINPLACE_CMD} -e 's|share/gramps|share/gnome/gramps|' \
		${WRKSRC}/src/Makefile.in \
		${WRKSRC}/src/docgen/Makefile.in
	@${REINPLACE_CMD} -e \
		's|share/application-registry|share/gnome/application-registry|; \
		 s|share/applications|share/gnome/applications|; \
		 s|share/mime-info|share/gnome/mime-info|' \
		${WRKSRC}/src/data/Makefile.in
	@${REINPLACE_CMD} -e \
		's|gramps\.png|${PREFIX}/share/gnome/gramps/gramps.png|' \
		${WRKSRC}/src/data/gramps.desktop
	@${REINPLACE_CMD} -e \
		's|/usr/share/gramps|${PREFIX}/share/gnome/gramps|' \
		${WRKSRC}/src/data/gramps.keys

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
