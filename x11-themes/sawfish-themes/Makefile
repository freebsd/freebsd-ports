# Created by: Alexey Mikhailov <karma@ez.pereslavl.ru>
# $FreeBSD$

PORTNAME=	sawfish-themes
PORTVERSION=	0.13
CATEGORIES=	x11-themes
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Themes for Sawfish window manager

LICENSE=	GPLv2

RUN_DEPENDS=	sawfish:x11-wm/sawfish

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

NO_BUILD=	yes

DATA_DIRS=	2YearsToNever Anonymous Aquiline BWM Big Blackwindow \
		Bubbles_Exact CoolClean Derivative DoubleHeliX Elberg Empire \
		FinalStep Greene2.0 Hacksaw HeliX Klarth Microtene \
		OrangeJuice SawLook SawthenaForever Strap Studio  T-16-blue \
		T-16-red T-16-yellow Titanium V absolute-metal bluefoo \
		debian gorilla gorillaz mxflat typo

post-extract:
	${FIND} ${WRKSRC} -name .xvpics | ${XARGS} ${RM} -rf

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/sawfish/themes
	cd ${WRKSRC} && ${COPYTREE_SHARE} "${DATA_DIRS}" \
		${STAGEDIR}${PREFIX}/share/sawfish/themes

.include <bsd.port.mk>
