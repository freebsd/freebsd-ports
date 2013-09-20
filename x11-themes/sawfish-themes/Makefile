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

RUN_DEPENDS=	sawfish:${PORTSDIR}/x11-wm/sawfish

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

NO_BUILD=	yes

DATA_DIRS=	2YearsToNever Anonymous Aquiline BWM Big Blackwindow \
		Bubbles_Exact CoolClean Derivative DoubleHeliX Elberg Empire \
		FinalStep Greene2.0 Hacksaw HeliX Klarth Microtene \
		OrangeJuice SawLook SawthenaForever Strap Studio  T-16-blue \
		T-16-red T-16-yellow Titanium V absolute-metal bluefoo \
		debian gorilla gorillaz mxflat typo

NO_STAGE=	yes
do-install:
	@${MKDIR} ${PREFIX}/share/sawfish/themes
.for d in ${DATA_DIRS}
	@${TAR} --exclude ".pc" --exclude ".xvpics" -C ${WRKSRC} -cf - ${d} | \
		${TAR} -C ${PREFIX}/share/sawfish/themes -xf -
	@${FIND} ${PREFIX}/share/sawfish/themes/${d} | \
		${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	@${FIND} ${PREFIX}/share/sawfish/themes/${d} -type f | \
		${XARGS} ${CHMOD} ${SHAREMODE}
	@${FIND} ${PREFIX}/share/sawfish/themes/${d} -type d | \
		${XARGS} ${CHMOD} a+rx
.endfor

.include <bsd.port.mk>
