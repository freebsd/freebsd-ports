# Created by: Vsevolod Stakhov <vsevolod@highsecure.ru>
# $FreeBSD$

PORTNAME=	metromap
PORTVERSION=	0.1.4
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://metromap.antex.ru/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Simple application for finding paths in different subways maps

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/COPYING

USES=		gettext gmake gnome python:2.7 shebangfix tar:bzip2
SHEBANG_FILES=	metromap.py modules/*.py
USE_GNOME=	pygtk2
NO_ARCH=	yes

PLIST_FILES=	bin/metromap \
		share/applications/metromap.desktop \
		share/icons/hicolor/48x48/apps/metromap.png \
		share/locale/ru/LC_MESSAGES/metromap.mo
PORTDOCS=	AUTHORS NEWS README README.data TODO
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} 's, python , ${PYTHON_CMD} ,' ${WRKSRC}/locale/Makefile

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
