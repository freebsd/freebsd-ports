# Created by: Andreas Fehlner <fehlner@gmx.de>
# $FreeBSD$

PORTNAME=	gramps
PORTVERSION=	3.3.0
PORTREVISION=	2
CATEGORIES=	science gnome python
MASTER_SITES=	SF/${PORTNAME}/Stable/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	freebsd-ports@herveybayaustralia.com.au
COMMENT=	A GTK/GNOME-based genealogy program

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bsddb>0:${PORTSDIR}/databases/py-bsddb \
		${PYXML}

USE_BDB=	43
USE_PYTHON=	2.6+
USE_GMAKE=	yes
USES=		desktop-file-utils gettext pathfix shared-mime-info
USE_GNOME=	pygnome2 pygnomeextras gnomedocutils
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ENV+=	GMSGFMT="${LOCALBASE}/bin/msgfmt"
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		gramps.1
MANLANG=	"" cs fr nl pl sv

OPTIONS_DEFINE=	ENCHANT PYWEBKITGTK GRAPHVIZ EXIV
OPTIONS_DEFAULT=	PYWEBKITGTK GRAPHVIZ EXIV
ENCHANT_DESC=		Spellchecking support
PYWEBKITGTK_DESC=	Use webkit backend for Geographic view
EXIV_DESC=		Managing exiv metadata support

.include <bsd.port.options.mk>

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

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
