# New ports collection makefile for:	gramps
# Date created:		2003-12-25
# Whom:			Andreas Fehlner <fehlner@gmx.de>
#
# $FreeBSD$

PORTNAME=	gramps
PORTVERSION=	2.2.8
PORTREVISION=	1
CATEGORIES=	science gnome python
MASTER_SITES=	SF

MAINTAINER=	freebsd@troback.com
COMMENT=	A GTK/GNOME-based genealogy program

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_bsddb.so:${PORTSDIR}/databases/py-bsddb \
		${PYTHON_LIBDIR}/site-packages/_xmlplus/__init__.py:${PORTSDIR}/textproc/py-xml

USE_BDB=	42+
USE_XLIB=	yes
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pygnome2 pygnomeextras desktopfileutils gnomedocutils
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--mandir=${MANPREFIX}/man

MAN1=		gramps.1
MANLANG=	"" fr
GCONF_SCHEMAS=	gramps.schemas

.include <bsd.port.mk>
