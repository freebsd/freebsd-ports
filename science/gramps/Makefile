# New ports collection makefile for:	gramps
# Date created:		2003-12-25
# Whom:			Andreas Fehlner <fehlner@gmx.de>
#
# $FreeBSD$

PORTNAME=	gramps
PORTVERSION=	3.2.3
CATEGORIES=	science gnome python
MASTER_SITES=	SF/${PORTNAME}/Stable/${PORTVERSION}

MAINTAINER=	freebsd@troback.com
COMMENT=	A GTK/GNOME-based genealogy program

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_bsddb.so:${PORTSDIR}/databases/py-bsddb \
		${PYTHON_LIBDIR}/site-packages/_xmlplus/__init__.py:${PORTSDIR}/textproc/py-xml

LICENSE=	GPLv2
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
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

OPTIONS=	ENCHANT "Spellchecking support" off \
		PYWEBKITGTK "Use webkit backend for Geographic view" on \
		GRAPHVIZ "Use graphviz for graphs creating" on

.include <bsd.port.pre.mk>

.if defined(WITH_ENCHANT)
RUN_DEPENDS+=${PYTHON_PKGNAMEPREFIX}enchant>=0:${PORTSDIR}/textproc/py-enchant
.endif
.if defined(WITH_PYWEBKITGTK)
RUN_DEPENDS+=${PYTHON_PKGNAMEPREFIX}webkitgtk>=0:${PORTSDIR}/www/py-webkitgtk
.endif
.if defined(WITH_GRAPHVIZ)
RUN_DEPENDS+=${PYTHON_PKGNAMEPREFIX}graphviz>-0:${PORTSDIR}/graphics/py-graphviz
.endif

pre-everything::
	@${ECHO_MSG} "WARNING: The on-disk structure of the databases has"
	@${ECHO_MSG} "changed since version 2.2.x."
	@${ECHO_MSG} "Cancel this installation now and export your databases"
	@${ECHO_MSG} "to GRAMPS XML file format as gedcom if you have not"
	@${ECHO_MSG} "already have done so."

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
