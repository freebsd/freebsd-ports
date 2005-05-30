# New ports collection makefile for:	metacity-bluecurve-theme
# Date created:			29 May 2005
# Whom:				Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	metacity-bluecurve-theme

COMMENT=	The Bluecurve Metacity themes

MASTERDIR=	${.CURDIR}/../bluecurve-themes

NO_BUILD=	yes
USE_GNOME=	gnomehier

.for t in Bluecurve Bluecurve-classic
BC_HIERS+=	${WRKSRC}/art/metacity/${t}:${PREFIX}/share/gnome/themes/${t}/metacity-1
PLIST_DIRS+=	share/gnome/themes/${t}/metacity-1 share/gnome/themes/${t}
.endfor

.include "${MASTERDIR}/Makefile"
