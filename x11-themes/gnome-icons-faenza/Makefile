# Created by: Pawel Pekala <pawel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	faenza
PORTVERSION=	1.3
CATEGORIES=	x11-themes gnome
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PROJECTHOST=	${PORTNAME}-icon-theme
PKGNAMEPREFIX=	gnome-icons-
DISTNAME=	${PROJECTHOST}_${PORTVERSION}

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Faenza GNOME 2 icon themes

LICENSE=	GPLv3

USE_ZIP=	yes
NO_BUILD=	yes
INSTALLS_ICONS=	yes

THEMES=		Faenza Faenza-Dark Faenza-Darkest Faenza-Darker \
		Faenza-Ambiance Faenza-Radiance
FAENZA_LIGHT=	Faenza
FAENZA_DARK=	Faenza-Dark

do-install:
.for theme in ${THEMES}
	@cd ${WRKDIR} && ${TAR} -xf ${theme}.tar.gz

.if ${FAENZA_LIGHT} == ${theme} || ${FAENZA_DARK} == ${theme}
	@cd ${WRKDIR}/${theme}/places/scalable && \
	${LN} -sf start-here-gnome.svg start-here.svg && \
	${LN} -sf start-here-gnome-symbolic.svg start-here-symbolic.svg
.for size in 22 24 32 48 64 96
	@cd ${WRKDIR}/${theme}/places/${size} && \
	${LN} -sf start-here-gnome.png start-here.png
.endfor
.endif

	${CP} -R ${WRKDIR}/${theme} ${PREFIX}/share/icons
	@cd ${PREFIX} && ${FIND} share/icons/${theme} ! -type d >> ${TMPPLIST} && \
		${FIND} share/icons/${theme} -type d | ${SORT} -r | \
		${SED} 's|^|@dirrm |' >> ${TMPPLIST}
.endfor

.include <bsd.port.mk>
