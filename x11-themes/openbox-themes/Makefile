# Created by: Roman Bogorodskiy <novel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openbox-themes
PORTVERSION=	1.0.2
CATEGORIES=	x11-themes
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Themes for Openbox

BROKEN=		unfetchable

LICENSE=	GPLv2

RUN_DEPENDS=	openbox:x11-wm/openbox

NO_BUILD=	yes
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-extract:
	@${RM} -r ${WRKSRC}/debian

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/themes
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/themes

.include <bsd.port.mk>
