# Created by: Filippo Natali <filippo@widestore.net>
# $FreeBSD$

# Port logic gratuitously stolen from x11-themes/kde-icons-noia by
# lioux@.  If it's not defined here and you think it should be, check
# x11-themes/gnome-icons/bsd.gnome-icons.mk for it.

PORTNAME=	lila
PORTVERSION=	0.6.4
PORTREVISION=	1
CATEGORIES=	x11-themes gnome
MASTER_SITES=	SF/lila-theme/lila-gnome/${PORTVERSION}
DISTNAME=	${PORTNAME}-gnome_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lila Icons for Gnome

RESTRICTED=	${REASON}

NO_WRKSUBDIR=	yes

USES=	tar:bzip2

.include "${.CURDIR}/../gnome-icons/bsd.gnome-icons.mk"
.include <bsd.port.mk>
