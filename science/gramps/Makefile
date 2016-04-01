# Created by: Andreas Fehlner <fehlner@gmx.de>
# $FreeBSD$

PORTNAME=	gramps
PORTVERSION=	3.4.9
PORTREVISION=	3
CATEGORIES=	science gnome python
MASTER_SITES=	SF/${PORTNAME}/Stable/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK/GNOME-based genealogy program

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bsddb>0:databases/py-bsddb \
		${PYTHON_PKGNAMEPREFIX}pyicu>=1.8:devel/py-pyicu

NO_ARCH=	yes
USE_BDB=	5+
USES=		desktop-file-utils gettext shared-mime-info gmake python:2
USE_GNOME=	pygtk2 intltool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-mime-install
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	ENCHANT PYWEBKITGTK GNOME GRAPHVIZ EXIV
OPTIONS_DEFAULT=	PYWEBKITGTK GRAPHVIZ EXIV
ENCHANT_DESC=		Spellchecking support
PYWEBKITGTK_DESC=	Use webkit backend for Geographic view
EXIV_DESC=		Managing exiv metadata support

ENCHANT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}enchant>=0:textproc/py-enchant
EXIV_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}exiv2>=0.1.3:graphics/py-exiv2
GNOME_USE=		GNOME=pygnome2,gnomedocutils
GRAPHVIZ_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygraphviz>=0:graphics/py-pygraphviz
PYWEBKITGTK_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}webkitgtk>=0:www/py-webkitgtk

pre-extract:
	@${ECHO_MSG} "=========================================================="
	@${ECHO_MSG} "*WARNING*: The Berkeley DB has been upgraded to version 5."
	@${ECHO_MSG} "Cancel this installation now and export your databases if"
	@${ECHO_MSG} "you are upgrading from a Gramps version older than 3.4.X"
	@${ECHO_MSG} "=========================================================="
	@sleep 5

.include <bsd.port.mk>
