# New ports collection makefile for:	gnome-icons-faenza
# Date created:		2011-12-27
# Whom:			Pawel Pekala <pawel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	faenza
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	x11-themes gnome
MASTER_SITES=	http://fc05.deviantart.com/fs71/f/2011/320/4/f/
PKGNAMEPREFIX=	gnome-icons-
DISTNAME=	${PORTNAME}_icons_by_tiheum-d2v6x24

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
.endfor

.include <bsd.port.mk>
