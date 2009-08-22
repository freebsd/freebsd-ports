# New ports collection makefile for:	gramps
# Date created:		2003-12-25
# Whom:			Andreas Fehlner <fehlner@gmx.de>
#
# $FreeBSD$

PORTNAME=	gramps
PORTVERSION=	3.0.4
PORTREVISION=	3
CATEGORIES=	science gnome python
MASTER_SITES=	SF/${PORTNAME}/Stable/${PORTVERSION}

MAINTAINER=	freebsd@troback.com
COMMENT=	A GTK/GNOME-based genealogy program

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_bsddb.so:${PORTSDIR}/databases/py-bsddb \
		${PYTHON_LIBDIR}/site-packages/_xmlplus/__init__.py:${PORTSDIR}/textproc/py-xml

USE_BDB=	43
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pygnome2 pygnomeextras desktopfileutils gnomedocutils
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ENV+=	GMSGFMT="${LOCALBASE}/bin/msgfmt"

MAN1=		gramps.1
MANLANG=	"" fr nl pl sv

.include <bsd.port.pre.mk>

pre-everything::
	@${ECHO_MSG} "WARNING: The on-disk structure of the databases has"
	@${ECHO_MSG} "changed since version 2.2.x."
	@${ECHO_MSG} "Cancel this installation now and export your databases"
	@${ECHO_MSG} "to GRAMPS XML file format as gedcom if you have not"
	@${ECHO_MSG} "already have done so."

.include <bsd.port.post.mk>
