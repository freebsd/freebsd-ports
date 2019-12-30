# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-st

COMMENT=	Remmina plugin for (Simple) Terminal use cases

RUN_DEPENDS=    ${LOCALBASE}/share/icons/hicolor/scalable/emblems/remmina-tool-symbolic.svg:net/remmina-plugin-exec # Shared icon file deleted below

USES=		gnome
USE_GNOME=	cairo

post-install:
	${RM} -rv ${STAGEDIR}${PREFIX}/share/icons

MASTERDIR=	${.CURDIR}/../remmina-plugins

.include "${MASTERDIR}/Makefile"
