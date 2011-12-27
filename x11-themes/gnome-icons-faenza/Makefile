# New ports collection makefile for:	gnome-icons-faenza
# Date created:		2011-12-27
# Whom:			Pawel Pekala <pawel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	faenza
PORTVERSION=	1.2
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

do-install:
.for i in ${THEMES}
	@cd ${WRKDIR} && ${TAR} -xf ${i}.tar.gz
	${CP} -R ${WRKDIR}/${i} ${PREFIX}/share/icons
.endfor

.include <bsd.port.mk>
