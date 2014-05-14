# Created by: Nicole Reid <root@cooltrainer.org>
# $FreeBSD$

PORTNAME=	elementary
PORTVERSION=	3.0
CATEGORIES=	x11-themes gnome
MASTER_SITES=	https://cooltrainer.org/freebsd-ports/gnome-icons-elementary/

MAINTAINER=	root@cooltrainer.org
COMMENT=	Elementary icon set

LICENSE=	GPLv2

USES=	zip:infozip
EXTRACT_AFTER_ARGS?=	-d ${WRKDIR} -x 'elementary/.bzrignore'

.include "${.CURDIR}/../gnome-icons/bsd.gnome-icons.mk"
.include <bsd.port.mk>
