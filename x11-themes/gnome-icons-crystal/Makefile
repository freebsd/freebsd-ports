# New ports collection makefile for:	Gnome iconset Crystal SVG
# Date created:				29 Feb 2004
# Whom:					Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#

# Port logic gratuitously stolen from x11-themes/kde-icons-noia by
# lioux@.  If it's not defined here and you think it should be, check
# x11-themes/gnome-icons/bsd.gnome-icons.mk for it.

PORTNAME=	crystal
PORTVERSION=	1.2.0
PORTREVISION=	4
CATEGORIES=	x11-themes gnome
MASTER_SITES=	SF/${PORTNAME}forgnome/Crystal%20SVG%20Icons/v${PORTVERSION}
DISTNAME=	CrystalSVG-${PORTVERSION}
EXTRACT_SUFX=	.bz2

MAINTAINER=	tmclaugh@FreeBSD.org
COMMENT=	Crystal SVG Icons for Gnome

RESTRICTED=	${REASON}

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/CfG-Crystal-SVG-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} 's|\(^Directories=.*\),,|\1,|' ${WRKSRC}/index.theme

.include "${.CURDIR}/../gnome-icons/bsd.gnome-icons.mk"
.include <bsd.port.mk>
