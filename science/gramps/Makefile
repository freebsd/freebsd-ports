# New ports collection makefile for:	gramps
# Date created:		2003-12-25
# Whom:			Andreas Fehlner <fehlner@gmx.de>
#
# $FreeBSD$
#    $MCom: ports/science/gramps/Makefile,v 1.2 2006/10/10 20:22:19 mezz Exp $
#

PORTNAME=	gramps
PORTVERSION=	2.2.6
PORTREVISION=	1
CATEGORIES=	science gnome python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gramps

MAINTAINER=	freebsd@troback.com
COMMENT=	A GTK/GNOME-based genealogy program written in Python

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_bsddb.so:${PORTSDIR}/databases/py-bsddb \
		${PYTHON_LIBDIR}/site-packages/_xmlplus/__init__.py:${PORTSDIR}/textproc/py-xml

USE_XLIB=	yes
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pygnome2 pygnomeextras desktopfileutils gnomedocutils
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes

MAN1=		gramps.1
GCONF_SCHEMAS=	gramps.schemas

USE_BDB=	42+
INVALID_BDB_VER=	2 3 40 41

.include <bsd.port.mk>
