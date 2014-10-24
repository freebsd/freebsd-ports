# Created by: Andreas Fehlner <fehlner@gmx.de>
# $FreeBSD$

PORTNAME=	gramps
PORTVERSION=	3.4.8
PORTREVISION=	3
CATEGORIES=	science gnome python
MASTER_SITES=	SF/${PORTNAME}/Stable/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK/GNOME-based genealogy program

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bsddb>0:${PORTSDIR}/databases/py-bsddb \
		${PYTHON_PKGNAMEPREFIX}icu>=1.8:${PORTSDIR}/devel/py-icu \
		${PYXML}

USE_BDB=	5+
USES=		desktop-file-utils gettext shared-mime-info gmake python
USE_GNOME=	pygtk2
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

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNOME}
USE_GNOME=	pygnome2 pygnomeextras gnomedocutils
.endif
.if ${PORT_OPTIONS:MENCHANT}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}enchant>=0:${PORTSDIR}/textproc/py-enchant
.endif
.if ${PORT_OPTIONS:MPYWEBKITGTK}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}webkitgtk>=0:${PORTSDIR}/www/py-webkitgtk
.endif
.if ${PORT_OPTIONS:MGRAPHVIZ}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}graphviz>-0:${PORTSDIR}/graphics/py-graphviz
.endif
.if ${PORT_OPTIONS:MEXIV}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}exiv2>=0.1.3:${PORTSDIR}/graphics/py-exiv2
.endif

pre-extract:
	@${ECHO_MSG} "=========================================================="
	@${ECHO_MSG} "*WARNING*: The Berkeley DB has been upgraded to version 5."
	@${ECHO_MSG} "Cancel this installation now and export your databases if"
	@${ECHO_MSG} "you are upgrading from a Gramps version older than 3.4.X"
	@${ECHO_MSG} "=========================================================="
	@sleep 5

.include <bsd.port.mk>
